cmake_minimum_required(VERSION 2.8)
project(Euchre CXX)

set (CMAKE_CXX_STANDARD 11)

include(gtest.cmake)
find_package(Threads)

add_executable(euchre src/main.cpp src/card.cpp src/cardmanager.cpp)


add_executable(euchre-test tests/main.cpp)
target_link_libraries(euchre-test gtest ${CMAKE_THREAD_LIBS_INIT})