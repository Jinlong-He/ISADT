MESSAGE(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})

ADD_SUBDIRECTORY(Model)
ADD_SUBDIRECTORY(Parser)
ADD_SUBDIRECTORY(CodeGenerator)
ADD_EXECUTABLE(isadt main.cpp)
#ADD_EXECUTABLE(isadt main_verify.cpp)
TARGET_LINK_LIBRARIES(isadt Model CodeGenerator Parser)
