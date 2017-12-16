#!/bin/bash


default_location=northcentralus

# initialize Azure
if [ $# -ne 1 ]; then
    echo "Usage: ./azInit.sh [desired_location]"
    while true; do
    read -p "Use default location (northcentralus)?" yn
    case $yn in
        [Yy]* ) default_location=$1; break;;
        [Nn]* ) echo "Supply desired location and rerun script" ; exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
fi



#login to Azure if not already done so
az account show 1> /dev/null

if [ $? != 0 ];
then
    az login
fi

# check if resource group exists
ExistsFlag=`az group exists -n myResourceGroupVM`
if [ $ExistsFlag -ne "true" ]; then
    az group create -l $default_location -n myResourceGroupVM
fi

