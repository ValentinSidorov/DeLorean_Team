#include "include/test_prog.hpp"

#include <string.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void print_hello(void) {
  std::cout << "Hello world!\n";

  std::ofstream fout("filename.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";
  }

  fout << "Hello world!\n";

  fout.close();

  exit(0);
}

void print_arg(const std::string& str) {
  std::cout << str << std::endl;

  std::ofstream fout("filename1.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";
  }

  fout << str << std::endl;

  fout.close();

  exit(0);
}

void print_arg2(const std::string& str1, const std::string& str2) {
  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;

  std::ofstream fout("filename2.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";
  }

  fout << str1 << std::endl;
  fout << str2 << std::endl;

  fout.close();

  exit(0);
}

void print_arg3(const std::string& str3) {
  std::cout << str3 << std::endl;

  std::ofstream fout("filename3.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";
    exit(0);
  }

  int num = 0;

  std::cout << "endless loop begins" << std::endl;

  while (true) {
    std::cout << str3 << std::endl;

    fout << str3 << std::endl;

    num++;

    sleep(5);
  }
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    print_hello();

    exit(0);

  }

  else if ((strstr(argv[1], "--text=") != NULL) && argc == 2) {
    string str(argv[1]);

    int n = str.find('=');

    if (n < str.length()) {
      str.erase(0, n + 1);
    }

    print_arg(str);

  }

  else if (argc == 3 && (strstr(argv[1], "--text1=") != NULL) &&
           (strstr(argv[2], "--text2=") != NULL)) {
    string str1(argv[1]);

    int n1 = str1.find('=');

    if (n1 < str1.length()) {
      str1.erase(0, n1 + 1);
    }

    string str2(argv[2]);

    int n2 = str2.find('=');

    if (n2 < str2.length()) {
      str2.erase(0, n2 + 1);
    }

    print_arg2(str1, str2);

    exit(0);

  }

  else if (argc == 3 && (strstr(argv[1], "--text=") != NULL) &&
           argv[2] == string("--loop")) {
    string str3(argv[1]);

    int n3 = str3.find('=');

    if (n3 < str3.length()) {
      str3.erase(0, n3 + 1);
    }

    print_arg3(str3);

    exit(0);
  } else {
    cout << "You've made an error while entering the arguments, try again"
         << endl;
  }

  return 0;
}
