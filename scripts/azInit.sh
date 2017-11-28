#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: ./azInit.sh [run_commands_file]"
	exit -1
fi


# ensure that $USER is referring to the current username
USER=`whoami`

az vm create --resource-group myResourceGroupVM \
        --name myVM --image UbuntuLTS --generate-ssh-keys
az vm start --resource-group myResourceGroupVM --name myVM
az vm list-ip-addresses --output json > temp.json # used to get dyn. IP addr
VM_IP=`python get_ip.py temp.json`
rm temp.json
scp -o StrictHostKeyChecking=no ${1} $USER@$VM_IP:/home/$USER # copy commands to VM

# TODO: create "temp.json" dynamically
az vm extension set --resource-group myResourceGroupVM \ # run commands on VM
    --vm-name myVM --name customScript \
    --publisher Microsoft.Azure.Extensions --settings ./tempCommand.json
scp ${USER}@${VM_IP}:/home/${USER}/temp.txt . # copy output from VM
az vm stop --resource-group myResourceGroupVM --name myVM
az vm delete --resource-group myResourceGroupVM --name myVM --yes