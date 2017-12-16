#!/usr/bin/python

# DEPRECATED
# gets the dynamic public IP address of the VM when it is launched

import json
import sys

if len(sys.argv) != 2:
    print("Usage: python get_ip.py [ip_list.json]")
    exit()

ip_list_file = sys.argv[1]

with open(ip_list_file) as f:
    data = json.load(f)
    print(data[0]['virtualMachine']['network']
          ['publicIpAddresses'][0]['ipAddress'])
