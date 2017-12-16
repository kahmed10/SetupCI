#!/bin/bash

if [ $SETUP_CI -eq "" ]; then
    echo "environment variable \$SETUP_CI not found. Please rerun installation"
    exit -1
fi

# installs Azure on Linux Systems
curl -L https://aka.ms/InstallAzureCli | bash

$SETUP_CI/scripts/azInit.sh