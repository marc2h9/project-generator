#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <chrono>

inline void sleep(int milliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void generate_project();

inline void help_command() {
  system("clear");
  std::cout << "LIST OF COMMANDS" << std::endl;
  std::cout << "-h shows this list" << std::endl;
  std::cout << "-g generates projects" << std::endl;
  std::cout << "-x exits the program" << std::endl;
  std::cout << "ENTER TO EXIT:" << std::endl;
  std::cin.ignore();
  std::cin.ignore(1);
  return;
}

inline void exit_command() {
  system("clear");
  std::cout << "Goodbye!" << std::endl;
  for (int i=3; i>0; i--) {
    std::cout << i << std::endl;
    sleep(500);
  }
  return;
}
#endif
