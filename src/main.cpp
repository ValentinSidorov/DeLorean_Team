#include <iostream>

#include "process_start.h"
#include "yaml_parse.h"

#include "csignal"
#include <fstream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void signalHandler(int signum);

int main(int argc, char *argv[]) {
  signal(SIGCHLD, signalHandler);
  if (argc > 1) {
    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there
      // start all process
      for (auto one_program : program) {
        // save pid in struct variable
        // one_program.pid = start_process(one_program);
        start_process(one_program);
      }
      // wait until processes are done
      wait(nullptr);
    } catch (std::exception &ex) {
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    cout << "Pass config filename as first argument to program" << endl;
  }

  return 0;
}

//
// problem 1, when we have not one proccess, that ended in ONE TIME
void signalHandler(int signum) {
  pid_t pid;
  int all_children = 0;
  int exit_status;
  // return immediately if no child has exited
  int dont_wait = WNOHANG;
  pid = waitpid(all_children, &exit_status, dont_wait);
  ofstream file("file.txt", std::ios_base::app);
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
