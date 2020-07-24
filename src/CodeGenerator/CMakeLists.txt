MESSAGE(STATUS "CodeGenerator This is SOURCE dir " ${PROJECT_SOURCE_DIR})


ADD_LIBRARY(CodeGenerator CCodeGenerator.cpp CodeGenerator.cpp ImpleCodeGenerator.cpp Plugin.cpp)