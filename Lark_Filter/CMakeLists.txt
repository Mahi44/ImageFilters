cmake_minimum_required(VERSION 2.8)
project( Lark_Filter)

set(OpenCV_DIR "D:/softwares/opencv/build/install")


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Lark_Filter Lark_Filter.cpp )
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS: ${OpenCV_LIBS}")  
target_link_libraries( Lark_Filter ${OpenCV_LIBS} )