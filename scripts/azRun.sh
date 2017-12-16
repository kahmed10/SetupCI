#!/bin/bash

# runs commands on desired VM

if [ $# -ne 3 ]; then
	echo "Usage: ./azRun.sh [run_commands_file] [size (see Azure doc for list)] [ID]"
    echo "ID may be any arbitrary value to identify current run"
	exit -1
fi

if [ ! -f $1 ]; then
    echo "File passed in does not exist"
    exit -1
fi


# ensure that $USER is referring to the current username
USER=`whoami`


# create temporary command file
json_command="{\n\
  \"commandToExecute\": \"cd /home/${USER}; bash tempCommands.txt\"\n\
}"

echo -e $json_command > tempCommand.json
cat ${1} > tempCommands.txt

# create vm based on provided size
az vm create --resource-group myResourceGroupVM \
        --name myVM --image UbuntuLTS --size $2 --generate-ssh-keys &> temp.txt

if grep -q "Deployment failed" temp.txt; then
    echo "Incompatible VM name"
    exit -1
fi

rm -f temp.txt

# get VM IP (second field in table)
VM_IP=`az vm list-ip-addresses --output table | grep \
    -w "myVM" | awk '{print $2}'`
if [ $VM_IP -eq "" ]; then
    echo "Error: unable to find VM IP Address"
    exit -1
fi

scp -o StrictHostKeyChecking=no tempCommands.txt $USER@$VM_IP:/home/$USER # copy commands to VM
# run script in VM
az vm extension set --resource-group myResourceGroupVM \
        --vm-name myVM --name customScript \
        --publisher Microsoft.Azure.Extensions --settings ./tempCommand.json &> out.txt

# if there are any bugs, the deployment will fail
if grep -q "Deployment failed" out.txt; then
    echo "Test $3 failed!"
else
    echo "Test $3 passed!"
    rm out.txt
fi

# delete VM once the run is complete
az vm delete --resource-group myResourceGroupVM --name myVM --yes &> /dev/null

