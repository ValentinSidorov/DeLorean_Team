# main.cpp
Back to [README.md](../README.md)

The main code looks like this.

```
#include <iostream>

#include "logger.h"
#include "process_start.h"
#include "yaml_parse.h"

using namespace std;

int main(int argc, char *argv[]) {
  Logger::getInstance()->set_log_path("custom.log");
  LOG("Started", INFO);

  if (argc > 1) {
    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there
      // start all process
      for (auto &one_program : program) {
        // pid changes in function
        one_program.pid = start_process(one_program);
      }
      // wait until processes are done
      wait(nullptr);
    } catch (std::exception &ex) {
      //!!! stdout stream doesn't work in CHILD process(redirected to file)
      LOG(std::string("Ouch! That hurts, because: ") + ex.what(), ERROR);
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    LOG("Cant find config file: ", ERROR);
    cout << "Pass config filename as first argument to program" << endl;
  }
  LOG("Finished", INFO);
  return 0;
}
```


## Description:
![Class Diagram](https://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/ValentinSidorov/DeLorean_Team/SidorovValentin/docs/UML/Struct_prog.puml)

Graphically, the operation of the main code is shown in the figure above.
## Syntax:
```
main example.yml
```

## Parameters:
The input file is in yaml format. Where - name: the name of the process, executable-path: the final path and name of the file that is being run, stdout-config: - the receiver file configuration, file: the path and file name for output, mode: a parameter that indicates the method for creating the file ( truncate - new file, append appending data to the end of the file), cmd-arguments: initial arguments for the file to be run, - option-name: the argument itself.

## Returns:

As a result of the program execution, a log file appears. The log file displays the progress of the input script.

## Example Code:

 The input file example.yml in yaml format is shown below.
```
processes:
  - name: test_prog1
    executable-path: ../../build/test_prog
    stdout-config:
      file: test_prog1_out.txt
      mode: truncate
    cmd-arguments:
      - option-name: --text=helloo
  - name: test_prog2
    executable-path: ../../build/test_prog
    stdout-config:
      file: test_prog2_out.txt
      mode: truncate
    cmd-arguments:
      - option-name: --text=World
```
Program start.
```
main example.yml
```
