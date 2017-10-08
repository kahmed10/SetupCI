#!/usr/bin/python

# import os
import sys

if len(sys.argv) != 3:
    print("Usage: python clean_md.py [raw_md_file] [clean_md_file_location")
    exit()

# TESTS_PATH = os.pardir(".") + "/tests/"

# INT_PATH = os.pardir(".") + "/int"

md_file = sys.argv[1]

# make sure no paths are present in the front
clean_md_file = md_file.split("/")[-1].rstrip(".md") + "_clean.md"

clean_md_file_location = sys.argv[2]

clean_lines = []

try:
    with open(md_file) as f:
        for line in f:
            if line.startswith("[//]: #"):  # comment indicator required
                comment_line = line.split("[//]: #", 1)[1]
                if comment_line != "":
                    clean_lines.append(comment_line)
except IOError:
    print("Unable to open .md file")

# write the clean file
try:
    with open(clean_md_file_location + "/" + clean_md_file, "w") as f:
        for line in clean_lines:
            f.write(line)

except IOError:
    print("Error: unable to write clean .md file")
