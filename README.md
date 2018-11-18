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
  
  * `build/` -- Makefile, CMakeFiles, and the executable binary

  * `CMakeLists.txt` -- Configuration for CMake.
  
  * `README.md` -- This file.


## Updating Makefile
1. Edit file `CMakeLists.txt` and add the .cpp files to add_executable()
2. If there is something old from another system for example, delete all files from `build/` (e.g. `cd build` and `rm * -rf`)
3. run `cmake ..` in directory `build/`

## Compiling the the program
Run `make` in the directory `build/`.

## Run the program
The executable is in the `build/` directory