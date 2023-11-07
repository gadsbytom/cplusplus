cmake_minimum_required(VERSION 3.0)
project(MyImageProcessingProject)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add the executable that will be built from the source files
add_executable(image_processing src/image_processing.cpp)

# Link OpenCV libraries
target_link_libraries(image_processing ${OpenCV_LIBS})
