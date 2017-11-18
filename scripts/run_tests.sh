#!/bin/bash

test_files=${SETUP_CI}/tests/*
count=0
for i in $test_files; do
    let "count += 1"
    #echo $i
    clean_md_file=`python ${SETUP_CI}/scripts/clean_md.py $i ${SETUP_CI}/int/clean`
    #echo $clean_md_file
    ${SETUP_CI}/bin/file_parser $clean_md_file ubuntu unix macos
    if [ $? -eq 0 ]; then
        echo "Test ${count} Passed"
    else
        echo "Test ${count} Failed"
    fi
done
