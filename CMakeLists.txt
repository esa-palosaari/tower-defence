cmake_minimum_required(VERSION 2.0)

project(towerGame3)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# set the executable name
set(EXECUTABLE_NAME "TD3")

# define source files
 file(GLOB SRCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

 add_executable(${EXECUTABLE_NAME} ${SRCES})


# add sfml
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/cmake_modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# add tests
enable_testing()
add_subdirectory(test)
