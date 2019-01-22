# Review form for project 


## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and
scope. The extent of project is large enough to accommodate work for
everyone (2p)

The implementation corresponds to the selected topic and scope very well.
The extent of the project is fairly large and work could be well accommodated for everyone.  
2p.


  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

Overall the software structure is fairly appropriate and clear as well as documented well with diagrams.  
In some places, information hiding and const correctness could have been used more properly.  
The program code introduces hard coding in the sense that game parameters are not in a common place where they would be easily adjustable.  
Some code files are really long and difficult to read. They could be divided into smaller logical sections.  
A tip: Some of the comments in the code are really unnecessary since the code that is being commented is very self-explanatory.  
1.5p.


  * 1.3: Use of external libraries is justified and well documented. (2p)

The usage of SFML, Googletest and CMake is justified and documented well enough.  
2p.


## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2p)

Commits are frequent enough and somewhat logical although errors exist.
Some commits push binary data.  
Some commits repeat the behaviour of previous similar commits (e.g. cleaning code in multiple consecutive commits while not defining what the commits are cleaning in the commit message): these commits could have been squashed to one commit or the commit message could have more information.  
Some commits do multiple logically different changes (e.g. cleaning code from another place and adding something at the same time): these commits could have been separated or the commit message could specify why these changes are all in the same commit.  
A minor tip: do manual testing in a separate branch or environment, and only introduce final changes in the master branch because it is really meant for a working product.
Some commits are really unclear and not descriptive at all.  
1p.


  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

The distribution of roles is described well in the project plan and documentation. Everyone has been contributing to the project and work is logged very well.  
2p.


  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

Testing is documented to be mainly manual, which is for the most part fair enough for a project like this.  
Good that you have used Valgrind to check for memory leaks.  
Good that you have practised unit testing, but only one test case exists..  
1.5p.



## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

Building instructions are fairly short but informative enough. CMake is used which is nice.  
The provided CMakeLists.txt works only on Linux, which eliminates the possibility of having cross-platform compilable code. This would have been quite easy to accomplish with straghtforward use of CMake. As a side note, when running CMake, it generates useful warnings that could be easily fixed :)  
The directory "build" contains test code, why does the documentation advise to remove the contents of the directory?  
Many commits add and remove build files. Build files are platform-dependant and should only be generated at compile time. 
1.5p.  


  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

Memory management seems robust. Smart pointers are used where appropriate. R0/3/5 could have been followed more thoroughly in some cases.  
2p.


  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2p)

STL containers and functions are properly used where approrpiate.  
2p.


  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

The implementation seems to work robustly in normal usage.  
However, the code does not do error handling in the sense that functions can fail when given invalid input and every exception is not thoroughly thought of.  
One big downside is that the user cannot change the resolution or the size of the game screen. For example, on some computers stuck with certain display settings, the game is unplayable since a big part of the screen gets cut away.  
1p.



## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. (0-10p)

Minimum requirements are fulfilled. When evaluationg the additional features, things that are considered in this section are the short time frame of the project and the fact that the additional features can become huge different components in a larger project.  
That is, all the features combined make this project earn some extensiveness points.
6p.



## 5. Project plan (0-3p)

The project plan is generally good and informative enough. It explains the game and the motivation of the project well.  
3p.



## Total

25.5p
