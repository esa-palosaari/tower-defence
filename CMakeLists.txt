cmake_minimum_required(VERSION 2.0)

project(towerGameTitle)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# set the executable name
set(EXECUTABLE_NAME "TD3")

# define source files
add_executable(${EXECUTABLE_NAME} "${CMAKE_SOURCE_DIR}/src/GameTitle.cpp" "${CMAKE_SOURCE_DIR}/src/GameMenu.cpp"
"${CMAKE_SOURCE_DIR}/src/main.cpp" "${CMAKE_SOURCE_DIR}/src/Engine.cpp" "${CMAKE_SOURCE_DIR}/src/Enemy.cpp" "${CMAKE_SOURCE_DIR}/src/Tower.cpp" "${CMAKE_SOURCE_DIR}/src/Projectile.cpp" "${CMAKE_SOURCE_DIR}/src/UserGraphics.cpp")
# When running the whole thing:
# file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
# add_executable(${EXECUTABLE} ${SOURCES})


# add sfml
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/cmake_modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()



