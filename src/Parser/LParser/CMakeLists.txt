MESSAGE(STATUS "LParser This is SOURCE dir " ${PROJECT_SOURCE_DIR})
SET(src_dir
    generated/CLexer.cpp
    generated/CParser.cpp
    generated/CVisitor.cpp
    generated/CBaseVisitor.cpp
 )
FILE(GLOB antlr4-cpp-src
    third_party/antlr4-cpp-runtime/src/*.cpp
    third_party/antlr4-cpp-runtime/src/atn/*.cpp
    third_party/antlr4-cpp-runtime/src/dfa/*.cpp
    third_party/antlr4-cpp-runtime/src/misc/*.cpp
    third_party/antlr4-cpp-runtime/src/support/*.cpp
    third_party/antlr4-cpp-runtime/src/tree/*.cpp
    third_party/antlr4-cpp-runtime/src/tree/pattern/*.cpp
    third_party/antlr4-cpp-runtime/src/tree/xpath/*.cpp
)
ADD_LIBRARY (LParser LParser.cpp ${src_dir} ${antlr4-cpp-src})
