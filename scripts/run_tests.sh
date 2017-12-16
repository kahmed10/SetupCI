#!/bin/bash

if [ $SETUP_CI -eq "" ]; then
    echo "environment variable \$SETUP_CI not found. Please rerun installation"
fi

test_files=$SETUP_CI/tests/*
count=0

rm -f $SETUP_CI/int/clean/*
rm -f $SETUP_CI/int/commands/*

for i in $test_files; do
    let "count += 1"
    clean_md_file=`python ${SETUP_CI}/scripts/clean_md.py $i ${SETUP_CI}/int/clean`
    #echo $clean_md_file
    ${SETUP_CI}/bin/file_parser $clean_md_file ubuntu unix macos
    if [ $? -eq 0 ]; then
        echo "Test ${count} Passed"
    else
        echo "Test ${count} Failed"
    fi
done
