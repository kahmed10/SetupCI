#!/bin/bash

# run desired bash command file, or sample one from 

if [ $SETUP_CI = "" ]; then
    echo "environment variable \$SETUP_CI not found. Please rerun installation"
    exit -1
fi

if [ $# -ne 3 ]; then
    echo "Usage: ./run_vm_test.sh [commands_file] [size] [ID]"
    echo "ID may be any arbitrary value to identify current run"
    echo "Make sure Azure is setup correctly by running ./azInstall.sh"
    while true; do
    read -p "Use default test (starts) [y/N]?" yn
    case $yn in
        [Yy]* ) ${SETUP_CI}/scripts/azRun.sh \
        ${SETUP_CI}/int/commands/starts_README_ubuntu_commands.txt \
        Standard_A1 1; break;;
        [Nn]* ) echo "Supply desired arguments and rerun script" ; exit;;
        * ) echo "Please answer yes or no.";;
    esac
    exit -1
done
fi


