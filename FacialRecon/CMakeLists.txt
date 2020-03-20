cmake_minimum_required(VERSION 2.8.12)
project(facial_recon)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(../dlib-19.19/dlib dlib_build)

add_executable(facialRecon src/exercice_facialRecon.cpp)
target_link_libraries(facialRecon dlib::dlib)
