cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
project(System-Monitor-UT)

add_executable(UT
"./Debug_UT.cpp"
"../src/processor.cpp"
"../src/linux_parser.cpp"
"../src/process.cpp"
)

include_directories(
"../include/"
)