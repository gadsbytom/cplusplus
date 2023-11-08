cmake_minimum_required(VERSION 3.0)
project(MyImageProcessingProject)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Check if the PROCESSOR_NAME variable is passed and use it
if(NOT PROCESSOR_NAME)
  set(PROCESSOR_NAME "default_value")
endif()

# Add the executable that will be built from the source files
add_executable(all_processing src/main.cpp src/image_processor.cpp src/ocr_tesseract.cpp)

# Link OpenCV & Tesseract libraries
target_link_libraries(all_processing ${OpenCV_LIBS})
target_link_libraries(all_processing -llept -ltesseract)