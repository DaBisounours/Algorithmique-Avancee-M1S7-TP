cmake_minimum_required(VERSION 3.6)
project(M1S7_TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Program.cpp Program.h Expr.cpp Expr.h ExprToken.cpp ExprToken.h StringOperations.cpp StringOperations.h)
add_executable(M1S7_TP1 ${SOURCE_FILES})