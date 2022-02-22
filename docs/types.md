# Types
Back to [README.md](../README.md)

The structure code looks like this.
```
  struct set_prog_start {
  std::string name;             // Process name
  std::string executable_path;  // Absolute path to executable file
  std::string
      stdout_config_file;  // Path to log file storing stdout (no log file is
                           // created by default, provided path should exist).
  bool stdout_config_truncate;  // stdout redirect file write mode append or
                                // truncate (default: truncate).
  pid_t pid;                    // Program pid(0 - if not started)
  std::vector<std::string>
      cmd_arguments;  // Option name(e.g. -h, -filename my_file)
};
```

## Description:
![Class Diagram](https://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/ValentinSidorov/DeLorean_Team/SidorovValentin/docs/UML/Srtuct_vector.puml)

The structure is designed to store data after the file parser. The file is in yaml format.

## Syntax:
To use this structure, we will turn it on. We write the command to connect the header file.
```
#include "types.h"
```

## Parameters:
name - Process name. Conditional name of the process.

executable_path - Absolute path to executable file. 

stdout_config_file - Path to log file storing stdout (no log fileis created by default, provided path should exist).

stdout_config_truncate - stdout redirect file write mode append or  truncate (default: truncate).

pid - Program pid(0 - if program not started).

## Returns:


## Example Code:
```
#include "types.h"

std::vector<set_prog_start> parse_yaml(const std::string &filename) {
 std::string line;
 std::vector<set_prog_start> out;
...
...
}
```



