cmake_minimum_required(VERSION 3.6)
project(M1S7_TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Program.cpp Program.h Expr.cpp Expr.h OLD_ExprToken.cpp OLD_ExprToken.h StringOperations.cpp StringOperations.h Func.cpp Func.h ExprTokens/OperatorToken.cpp ExprTokens/OperatorToken.h ExprToken.cpp ExprToken.h ExprTokens/Operators/Operator.cpp ExprTokens/Operators/Operator.h ExprTokens/Operators/Add.cpp ExprTokens/Operators/Add.h ExprTokens/Operators/Multiply.cpp ExprTokens/Operators/Multiply.h ExprTokens/Operators/Divide.cpp ExprTokens/Operators/Divide.h ExprTokens/Operators/Subtract.cpp ExprTokens/Operators/Subtract.h)
add_executable(M1S7_TP1 ${SOURCE_FILES})