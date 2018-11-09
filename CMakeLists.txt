cmake_minimum_required(VERSION 2.0)

project(towerGameTitle)

include_directories(include)

# set the executable name
set(EXECUTABLE_NAME "GameTitle")

# define source files
add_executable(${EXECUTABLE_NAME} "${CMAKE_SOURCE_DIR}/src/GameTitle.cpp" "${CMAKE_SOURCE_DIR}/src/main.cpp")
# When running the whole thing:
#file(GLOB SOURCES "src/main.cpp" "src/GameTitle.cpp")
#add_executable(${EXECUTABLE} ${SOURCES})


# add sfml
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/cmake_modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()



