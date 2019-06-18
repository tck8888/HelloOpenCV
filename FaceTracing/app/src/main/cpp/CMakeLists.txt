cmake_minimum_required(VERSION 3.4.1)

add_library(
        native-lib
        SHARED
        native-lib.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-L${CMAKE_SOURCE_DIR}/src/main/jni/${ANDROID_ABI}")
target_link_libraries(
        native-lib
        log
        opencv_java3
        android
)