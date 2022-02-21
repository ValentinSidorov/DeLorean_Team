# Process start
Back to [README.md](../README.md)



## Description:
![Class Diagram](https://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/ValentinSidorov/DeLorean_Team/DenisProzor/docs/UML/process_start_function.puml)


## Syntax:
start_process(&program_struct)

## Parameters:
set_prog_start - Reference on structure contains information about process, that we need to start

## Returns:
1. On success - pid_t,process id, which was launched.
2. On error - 0, if we couldn't do fork. 

If we have some errors in child-part, child process will: 
* indicate another program wasn't laucnhed(change program.pid to zero)
* print error logs
* do exit(1)

## Example Code:
main(){
  set_prog_start test_program = {
      .name = "echo",
      .executable_path = "/bin/",
      .stdout_config_file = "",
      .stdout_config_truncate = 0,
      .pid = 0,
      .cmd_arguments = {},
  };
  int pid = start_process(test_program);
  return 0;
}
