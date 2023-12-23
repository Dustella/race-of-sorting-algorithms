cmake_minimum_required(VERSION 3.10)

# set the project name
project(SortingAlgorithm)

add_executable(main main.cpp
        sorting/interface.cpp
        framework/driver.cpp
        framework/gui.cpp
        sorting/AllSort.cpp
)