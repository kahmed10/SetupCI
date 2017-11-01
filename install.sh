#!/bin/bash

if [ ! -d "obj" ]; then
    mkdir obj
fi 

if [ ! -d "int" ]; then
    mkdir int
    mkdir int/clean
    mkdir int/commands
fi

make -C src/
