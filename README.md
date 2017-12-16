[//]: # (CI_RUN_UNIX(git clone https://gitlab.engr.illinois.edu/kahmed10/SetupCI.git))
[//]: # (CI_RUN_UBUNTU_PROMPT(sudo apt-get install clang))
[//]: # (CI_RUN_UBUNTU(sudo apt-get -f install))


This is the initial phase of SetupCI, a tool that performs regression testing on installation guides. Current support will begin with GitHub projects that have a .md file to parse.

The required dependencies for this tool are:
* clang 3.8 or greater

Before using this tool, run the following setup script:
```
source install.sh
```
[//]: # (CI_RUN_UNIX(cd SetupCI))
[//]: # (CI_RUN_UNIX_PROMPT_NO(source ./install.sh))

To parse the test README.md files, run:
```
 ./scripts/run_tests.sh
```
[//]: # (CI_RUN_UNIX(./scripts/run_tests.sh))

The generated command files can be found under: int/commands/

To test a command list locally, run:
```
 ./scripts/run_local.sh
```
WARNING: you must make sure that the commands in the file will not harm
your machine.

To test the VM process, make sure that Azure CLI is installed by running:
```
 ./scripts/azInstall.sh
```

Then, to run a sample README:
```
 ./scripts/run_vm_test.sh
```
Note: testing on the VM may take several minutes, and even longer depending
on the duration of the installation.