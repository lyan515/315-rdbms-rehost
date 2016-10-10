# rdbms

## Cloning Repo
Since there are submodules you have to recursively clone in the repo.  
`git clone --recursive https://github.tamu.edu/ameserole/rdbms.git`  

## View Deliverable 2  
Deliverable 2 was marked as an official release and is under the tag Deliverable-2.  
To view run the following command:  
`git checkout Deliverable-2`  

## View Deliverable 3  
Deliverable 3 was marked as an official release and is under the tag Deliverable-3.  
To view run the following command:  
`git checkout Deliverable-3`

## View Deliverable 4  
Deliverable 4 was marked as an official release and is under the tag Deliverable-4.  
The link to the final report is under the wiki.  
To view run the following command:  
`git checkout Deliverable-4`

## Run Interactive System  
To run the Interactive System on its own:  
Navigate to `interactiveSrc/` and run `python Interface.py`  
To run the parser server in the background and start the interactive system in one command run  
`./start.sh`  
This starts runs the server in the background on ip `127.0.0.1` and port `1337`. The output from the server gets logged in `log.txt`.

## Run Parser  
To run the parser on the command line run the following commands:  
Navigate to `engineSrc/` and run  
`make main`  
`./main -c |-s`  
`-c` runs the parser on the command line
`-s` runs the parser on a server with ip `127.0.0.1` and port number `1337`

## Running Unit Test
To run the parser unit tests run the following commands:  
`make parserTest`  
`./parserTests`  

There is currently a Seg Fault in the Unit Tests for the Parser but it runs with standard input  
To test from standard input you can run:  
`make main`  
`./main < parserCLITest`  
  
To run the engine unit tests run the following commands:  
`make engineTest`  
`./engineTests`  

## Submodules
Here are the sources for the submodules we are using.

Catch, A modern, C++-native, header-only, framework for unit-tests, TDD and BDD C++ Automated Test Cases in Headers:   https://github.com/philsquared/Catch/tree/master
