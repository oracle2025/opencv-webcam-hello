project(opencv_hello)

find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated")

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBRARIES}) 
