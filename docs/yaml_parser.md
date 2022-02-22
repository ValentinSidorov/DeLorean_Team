# yaml_parse.h
Back to [README.md](../README.md)
```
#include "yaml_parse.h"
```


## Description:
Unit that allows to parse yaml file of execution manager

## Syntax:

parse_yaml(filename);

## Parameters:
filename  - std::string  - path to file

## Returns:

struct set_prog_start which is described at [types.md](types.md)

## Example Code:

```
#include <iostream>
#include <types.h>
#include "yaml_parse.h"

using namespace std;

int main(int argc, char *argv[])
{
    auto program = parse_yaml(argv[1]);
    cout<<program[0].name;

    return 0;
}
```