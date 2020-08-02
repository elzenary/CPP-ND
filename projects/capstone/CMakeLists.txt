cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(HelloWorld)

add_executable(	miniBankSimulator
 src/main.cpp
 "src/UserDB.cpp"
 "src/UserRegister.cpp"
 "src/UserLogin.cpp"
 "ThirdParty/sha256.cpp"
 "src/bankOperations.cpp"
 "src/FSM.cpp"
 )
 
 include_directories(
"ThirdParty/"
"src/"

)

