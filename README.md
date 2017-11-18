[//]: # (CI_RUN_UNIX(git clone https://gitlab.engr.illinois.edu/kahmed10/SetupCI.git))

This is the initial phase of SetupCI, a tool that performs regression testing on installation guides. Current support will begin with GitHub projects that have a .md file to parse.

Before using this tool, run the following setup script:
```
./install.sh
```
[//]: # (CI_RUN_UNIX(cd SetupCI; ./install.sh))

To parse the test README.md files, run:
```
 ./scripts/run_tests.sh
```
[//]: # (CI_RUN_UNIX(./scripts/run_tests.sh))
