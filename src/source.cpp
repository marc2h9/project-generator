#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <string>

#include "headers/main.hpp"

bool check_command(std::string command);
bool awaiting_command();

bool check_command(std::string command) {
  std::unordered_map<std::string, int> commandmap = {
    {"-h", 0},
    {"-g", 1},
    {"-x", 2},
  };
  auto check = commandmap.find(command);
  if (check!=commandmap.end()) {
    int commandnum = check->second;
    switch (commandnum) {
      case 0:
        help_command();
        return false; 
      break;

      case 1:
        generate_project();        
        return false;
      break;

      case 2:
        exit_command();
        return true;
      break;

      default:

      break;
    }
  }
  return false;
}

bool awaiting_command() {
  system("clear");
  std::cout << "Awaiting command type \"-h\" for commands" << std::endl;
  std::string command;
  std::cin >> command; 
  bool exit = check_command(command);
  if (exit!=true) {
    return false;
  } else {
    return true;
  }
  return false;
}

int main() {
 bool stop = awaiting_command();
 do {
  stop = awaiting_command(); 
 } while (stop!=true);
 return 0; 
}
