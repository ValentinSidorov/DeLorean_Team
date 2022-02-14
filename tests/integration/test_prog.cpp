#include "include/test_prog.hpp"

#include <unistd.h>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void print_hello(void) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Hello world!\n";
  }

  std::ofstream fout("filename.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";

  } else {
    std::cout << "filename.txt has been successfully created, you can check it "
                 "out in your current directory\n";
  }

  int i = 0;

  while (i < 10) {
    fout << "Hello world!\n";
    i++;
  }

  fout.close();

  exit(0);
}

void print_arg(const std::string& str) {
  int i = 0;
  std::cout << "text output in console\n";

  for (i = 0; i < 10; i++) {
    std::cout << str << std::endl;
  }

  std::ofstream fout("filename1.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";

  } else {
    std::cout << "filename1.txt has been successfully created, you can check "
                 "it out in your current directory\n";
  }

  for (int i = 0; i < 10; i++) {
    fout << str << std::endl;
  }

  fout.close();
}

void print_arg2(const std::string& str1, const std::string& str2) {
  int i = 0;
  std::cout << "Text output in console\n";
  while (i < 10) {
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    i++;
  }

  std::ofstream fout("filename2.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";

  } else {
    std::cout << "filename2.txt has been successfully created, you can check "
                 "it out in your current directory\n";
  }

  for (int i = 0; i < 10; i++) {
    fout << str1 << std::endl;
    fout << str2 << std::endl;
  }

  fout.close();
}

void print_arg3(const std::string& str3) {
  int i = 0;
  std::cout << "Text output in conosle\n";
  while (i < 10) {
    std::cout << str3 << std::endl;
    i++;
  }

  std::ofstream fout("filename3.txt");

  if (!fout.is_open()) {
    std::cout << "mistake in opening the file\n";

  } else {
    std::cout << "filename4.txt has been successfully created, you can check "
                 "it out in your current directory\n";
  }

  int num = 0;

  std::cout << "the program with endless loop will be finished after five "
               "iterations, please wait"
            << std::endl;

  while (true) {
    std::cout << str3 << std::endl;

    fout << str3 << std::endl;

    num++;

    if (num == 5) {
      fout.close();

      break;
    }

    sleep(5);
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    string str(argv[1]);

    print_arg(str);

    if (argc < 3) {
      exit(0);
    }

    string str1(argv[2]);
    string str2(argv[3]);
    print_arg2(str1, str2);

    if (argc < 4) {
      exit(0);
    }

    string str3(argv[4]);
    print_arg3(str3);

    exit(0);
  }

  else {
    print_hello();
  }

  return 0;
}
