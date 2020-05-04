cmake_minimum_required(VERSION 2.8.12)
project(facial_recon)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(../dlib-19.19/dlib dlib_build)

if (DLIB_NO_GUI_SUPPORT)
   message("No GUI support, so we won't build the webcam_face_pose_ex example.")
else()
   find_package(OpenCV QUIET)
   if (OpenCV_FOUND)
      include_directories(${OpenCV_INCLUDE_DIRS})

      add_executable(facialRecon src/facialRecon.cpp)
      target_link_libraries(facialRecon dlib::dlib ${OpenCV_LIBS} )
   else()
      message("OpenCV not found, so we won't build the webcam_face_pose_ex example.")
   endif()
endif()
