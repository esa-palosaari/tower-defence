# README file for C++ programming project TowerDefence-3

This is a git repository the programming project TowerDefence-3.
It contains the following:

  * `plan/` -- Here is the project plan.

  * `doc/` -- here are the documentation sources related to the project.
    You may use different tools for documentation (e.g. latex),
    but we hope to get the final version of the document
    **also as pdf file**.

  * `src/` -- here are the C++ source files. 
  
  * `include/` -- The header files
  
  * `build/` -- Makefile, CMakeFiles, and the executable binary for the game
 
  * `build/test/` -- Executable binary for the tests

  * `test/` -- Googletest and game test source files 

  * `CMakeLists.txt` -- Configuration for CMake.
  
  * `README.md` -- This file.

## Requirements
The game requires the SFML library to compile. You can get download and installation instructions from [https://www.sfml-dev.org/](https://www.sfml-dev.org/).

## Updating Makefile
1. If there is something in `build/` (from another system for example) delete all files there (e.g. `cd build` and `rm * -rf`)
2. run `cmake ..` in directory `build/`

## Compiling the the program
Run `make` in the directory `build/`.

## Run the program
The executable is in the `build/` directory

## Run the tests
The executable is in the `build/test/` directory