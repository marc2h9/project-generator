#ifndef MAKEPROJECTS_CPP
#define MAKEPROJECTS_CPP
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_map>

#include "../headers/main.hpp"

void makefile_generator(std::string mainfilename, std::string mainheaderfilename, std::string projectfoldername);

void makefile_generator(std::string mainfilename, std::string mainheaderfilename, std::string projectfoldername) {
  std::string projectfoldercmd = "\tmkdir " + projectfoldername;
  std::string mainfilenamecmd = "\ttouch " + mainfilename + ".cpp";
  std::string mainheaderfilenamecmd = "\ttouch " + mainheaderfilename + ".hpp";
  std::unordered_map<int, std::string> commands = {
    {0,projectfoldercmd},
    {1,"\tmkdir src"},
    {2,"\ttouch README.md"},
    {3,"\tmv src " + projectfoldername},
    {4,mainfilenamecmd},
    {5,"\tmkdir headers"},
    {6,"\tmkdir scripts"},
    {7,"\tmv headers " + projectfoldername + "/src/"},
    {8,"\tmv scripts " + projectfoldername + "/src/"},
    {9,mainheaderfilenamecmd},
    {10,"\tmv " + mainheaderfilename + ".hpp " + projectfoldername +  "/src/headers/"},
    {11,"\tmv " + mainfilename + ".cpp "  + projectfoldername +  "/src/"},
    {12,"\tmv README.md " + projectfoldername},
    {13,"\trm makefile"},
  };
  std::ofstream makefile;
  system("touch makefile");
  makefile.open("makefile");
  makefile << "build:" << std::endl;
  for (int i=0; i!=14;) {
    auto cmd = commands.find(i);
    if (cmd!=commands.end()) {
      std::string cmdstring = cmd->second;
      makefile << cmdstring << "\n";
    }
    i++;
  }
  makefile.close();
  return;
}

void generate_project() {
  system("clear");
  std::cout << "Generating Project in C++ language..." << std::endl;
  std::cout << "Please type in the name of the project folders name [CANNOT CONTAIN SPACES]" << std::endl;
  std::string projectfoldername;
  std::cin.ignore();
  std::cin >> projectfoldername;

  sleep(500);
  system("clear");
  std::cout << "Please type in what the main file will be called without extension" << std::endl;
  std::string mainfile;
  std::cin.ignore();
  std::cin >> mainfile;

  sleep(500);
  system("clear");
  std::cout << "Please type in what the main header file will be called without extension" << std::endl;
  std::string mainheaderfile;
  std::cin.ignore();
  std::cin >> mainheaderfile;

  sleep(500);
  system("clear");
  std::cout << "Selections confirmed generating makefile..." << std::endl;
  makefile_generator(mainfile, mainheaderfile, projectfoldername);
  std::cout << "Makefile generated making project..." << std::endl;
  system("make");
  std::cout << "Finished making project...";
  sleep(3000);
  return;
}

#endif
