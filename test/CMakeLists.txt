find_package(Threads REQUIRED)

include_directories("../include")
include_directories("../src/")


# Game source code
file(GLOB SRCS "../src/*.cpp")
add_library(TD SHARED ${SRCS})

# add Googletest
ADD_SUBDIRECTORY(gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})



# make test executable
add_executable(runTests moneyTest.cpp)
target_link_libraries(runTests gtest gtest_main TD)


# add sfml
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/cmake_modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(runTests ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


add_test(runTests runTests)

