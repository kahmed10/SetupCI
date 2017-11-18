#!/bin/bash

if [ ! -d "obj" ]; then
    mkdir obj
fi 

if [ ! -d "int" ]; then
    mkdir int
    mkdir int/clean
    mkdir int/commands
fi


# check for versions of unix, setup environment variable
unixName=`uname -s`
case "${unixName}" in
    Linux*)
        if ! grep -q 'SETUP_CI' ~/.bashrc; then
            echo "export SETUP_CI=$PWD" >> ~/.bashrc
            source ~/.bashrc
        fi
        ;;
    Darwin*)
        if ! grep -q 'SETUP_CI' ~/.bash_profile; then
            echo "export SETUP_CI=$PWD" >> ~/.bash_profile
            source ~/.bash_profile
        fi
        ;;
    *)
        echo "Incompatible OS"
        exit 1
esac


make -C src/
