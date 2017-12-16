#!/bin/bash

# run bash command file locally and check if passed

if [ $# -ne 2 ]; then
    echo "Usage: ./run_local.sh [commands_file] [ID]"
    echo "ID may be any arbitrary value to identify current run"
    echo "WARNING: make sure sudo commands are SAFE when running locally!"
    exit -1
fi

bash $1 2>out.txt
if [ ! -s out.txt ]; then
    echo "Test $2 passed!"
    rm out.txt
else
    echo "Test $2 failed!"
fi

