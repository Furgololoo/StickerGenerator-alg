cmake_minimum_required(VERSION 3.24)
project(StickGen VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.75.0 REQUIRED COMPONENTS json filesystem)

if(Boost_FOUND)
    message(STATUS "Boost library status: ")
    message(STATUS "    version: ${Boost_VERSION}")
    message(STATUS "    libraries: ${Boost_LIBRARIES}")
    message(STATUS "    include dirs: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(OpenCV REQUIRED)
    message(STATUS "OpenCV library status: ")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(StickGen
        src/main.cpp

        src/sticker.cpp src/sticker.h
        src/page.cpp src/page.h
)

target_link_libraries(StickGen ${OpenCV_LIBS})
target_link_libraries(StickGen ${Boost_LIBRARIES})
