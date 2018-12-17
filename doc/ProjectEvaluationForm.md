# Review form for project towerdefence-3

**Name of project to be reviewed: towerdefense-3**

**Names of reviewers:**
Oskar Tainio 590138
Katariina Tuovinen 561507
Arsi Ikäheimonen 47130M
Esa Palosaari 618573

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and
scope. The extent of project is large enough to accommodate work for
everyone (2p)




The project implemented the selected topic with both basic and a few additional 
features. The project was large enough to accommodate work for everyone. *2p*


  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

Class structure is robust and logical. Class references work correctly and with 
minimal effort. Instead of inherited classes we used different types for towers 
and enemies. Class sizes are optimized by dividing them into smaller chunks 
instead of putting everything in one big file. In only a few cases did we stray 
from information hiding and used public variables.
*2p*

  * 1.3: Use of external libraries is justified and well documented. (2p)


We used the suggested SFML and provided its installation instructions (or links 
to the instructions). CMake is able to find the library from different locations 
and operating systems without user input. No other external library was needed 
for the program to work. *2p*


## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

Git commits were frequent and had descriptive comments. Group members were noted 
when large updates were made. *2p*

  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p) 

Work was distributed well. Everyone had a flexible role and had always something 
to do. Work was mostly done in pairs and therefore assistance was provided 
easily, which resulted in easier solving of problems. Roles did not alter very 
much from the original concept of the project plan. Working hours were balanced. *2p*


  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

The implementation was tested comprehensively: testing the game mostly involved 
running it to see if everything worked as expected. Memory leaks were tested 
both with Valgrind and the compiler. There was one unit test done with 
Googletest. All the testing principles and results were documented. *2p*

## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

Building the software should be easy and the instructions are given in both the 
README file and in the documentation. Three commands are needed to build (cmake 
and make) and run (TD3) the game. CMake was used for configuring Makefiles. *2p*

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

Memory management was robust and no leaks were present (when tested with 
Valgrind and the g++ compiler). Smart pointers were used to handle projectile 
objects. However, RO3/5 could have been used more widely when considering 
projectiles for example. 1p.

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

Standard library is used widely and no own solutions exist. Vectors are used as 
containers to handle towers, enemies and projectiles. Use of references and 
pointers is done correctly. *2p*

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

Exception handling is used widely when SFML-based content is loaded in game and 
it works correctly in every situation. Functions are mainly constructed so that 
no invalid inputs can possibly be done. *2p*

## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. (0-10p)

Additional features included: 
1. Sounds
2. A list of high scores that is saved locally
3. Upgradeable towers
4. Special attack types, e.g. ranged, explosions
5. Different attack and defense types for both the towers and the enemies.
6. (Main menu and Title screen as mainly cosmetic features.)

*6p*

