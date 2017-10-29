#!/bin/bash

if [ ! -d "obj" ]; then
    mkdir obj
fi 

if [ ! -d "int" ]; then
    mkdir int
fi

make -C src/
