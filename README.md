# README file for C++ programming project TowerDefence-3

This is a git repository the programming project TowerDefence-3.
It contains the following:

  * `plan/` -- Here is the project plan.

  * `doc/` -- Here are the documentation sources related to the project.

  * `src/` -- Here are the C++ source files. 
  
  * `include/` -- The header files.
  
  * `build/` -- Makefile, CMakeFiles, and the executable binary for the game.
 
  * `build/test/` -- Executable binary for the tests.

  * `test/` -- Googletest and game test source files.

  * `CMakeLists.txt` -- Configuration for CMake.
  
  * `README.md` -- This file.

## Requirements
The game requires CMake and the SFML library to compile. You can get download 
and installation instructions from [https://cmake.org](https://cmake.org) and 
[https://www.sfml-dev.org/](https://www.sfml-dev.org/).

## Updating Makefile
1. If there is something in `build/` (from another system for example) delete 
   all files there (e.g. `cd build` and `rm * -rf`).
2. run `cmake ..` in directory `build/`.

## Compiling the the program
Run `make` in the directory `build/`.

## Run the program
The executable `TD3` is in the `build/` directory.

## Run the tests
The executable `runTests` is in the `build/test/` directory.