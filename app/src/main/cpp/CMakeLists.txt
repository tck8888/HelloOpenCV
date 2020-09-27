cmake_minimum_required(VERSION 3.4.1)


# opencv
set(OpenCV_STATIC ON)
set(OpenCV_DIR E:/OpenCV-android-sdk/sdk/native/jni)
message(STATUS "==== OpenCV libraries OpenCV_DIR: ${OpenCV_DIR}")
find_package(OpenCV REQUIRED)
message(STATUS "==== OpenCV libraries: ${OpenCV_LIBS}")

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        opencv-utils.cpp
        native-lib.cpp)

# jnigraphics lib from NDK is used for Bitmap manipulation in native code
find_library(jnigraphics-lib jnigraphics)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries( # Specifies the target library.
        native-lib
        ${OpenCV_LIBS}
        ${jnigraphics-lib}
        ${log-lib})