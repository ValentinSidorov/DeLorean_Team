# logger.h
Back to [README.md](../README.md)
```
#include "logger.h" 
```
Logger singleton added

for using

add to your unit
 where "message" is std::string and 
Example in main.cpp and yaml_parse.cpp



Not tested with forked process yet.

## Description:

Module that allows log messages to file with log-leve and timestamp

## Syntax:

LOG("message", ERROR);

## Parameters:
message is std::string 
ERROR are enum DEBUG/INFO/WARN/ERROR

## Returns:

void

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