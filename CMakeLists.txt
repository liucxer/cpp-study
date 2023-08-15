cmake_minimum_required(VERSION 3.19)
project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/rocksdb/6.27.3/include)
add_executable(cpp_study rocksdb/main.cpp)