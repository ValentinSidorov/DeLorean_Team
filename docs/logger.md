# logger.h
Back to [README.md](../README.md)
```
#include "logger.h" 
```

## Description:

Module that allows log messages to file with log-leve and timestamp

## Syntax:

LOG("message", ERROR);

## Parameters:
message is std::string 
ERROR are enum that marks type of message and allows to filter message by type:

DEBUG – The DEBUG Level designates fine-grained informational events that are most useful to debug an application.
INFO – The INFO level designates informational messages that highlight the progress of the application at coarse-grained level.
WARN – The WARN level designates potentially harmful situations.
ERROR – The ERROR level designates error events that might still allow the application to continue running.

## Returns:

As function returns void.
Also created text file (by default `custom.log` in working directory) with list of errors.

Example of output file:
```
23-02-2022 11-42-10 [INFO ] Started
23-02-2022 11-42-10 [INFO ] Parsed from config file: test_prog1
23-02-2022 11-42-10 [INFO ] Finished
```


## Example Code:
```
#include <iostream>
#include "logger.h" 
using namespace std;

int main()
{
    LOG("Started", INFO);
    cout<<"Hello World";
    LOG("Finished", INFO);

    return 0;
}
```
