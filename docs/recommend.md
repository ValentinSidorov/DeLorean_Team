# Recommendations for the future development of the project.

Back to [README.md](../README.md)


## Handle Process death

## Description:
We can add function to handle child processes death. Firstly, we need to set signal handler to SIGCHLD signal. When we get this signal - check what process dead and get it pid to do some other work(log it or start process again).


## Syntax:
void signalHandler(int signum);

## Example Code:
```
void signalHandler(int signum);

int main(int argc, char *argv[]){
  signal(SIGCHLD, signalHandler);
  start_process(one_program);
  auto program = parse_yaml(argv[1]);
  while(1)
    ;
  return 0;
}
void signalHandler(int signum) {
  pid_t pid;
  int all_children = 0;
  int exit_status;
  // return immediately if no child has exited
  int dont_wait = WNOHANG;
  pid = waitpid(all_children, &exit_status, dont_wait);
  ofstream file("file.log", std::ios_base::app);
  if (pid == -1) {
    file << "waitpid() error" << endl;
  } else {
    string status;
    if (WIFEXITED(exit_status)) {
      status = to_string(WEXITSTATUS(exit_status));
    } else if (WIFSIGNALED(exit_status)) {
      status = "Child process ended by a signal = ";
      status.append(to_string(WTERMSIG(exit_status)));
    } else {
      status = "Other error";
    }
    file << "Child is died" << endl
         << "Pid = " << pid << ", Status = " << status << endl;
  }
  file.close();
  return;
}
```