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
      // wait until ALL processes are done
      int process_status = 0;
      while (1) {
        int pid = wait(&process_status);
        // ECHILD - error, when we don't have alive processes
        if (pid == -1 && errno == ECHILD) {
          break;
        }
      };
    } catch (std::exception &ex) {
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
