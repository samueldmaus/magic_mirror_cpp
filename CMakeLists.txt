cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Mirror)

find_package(wxWidgets REQUIRED COMPONENTS core base)
find_package(cpprestsdk REQUIRED)

include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)

add_executable(mirror ${project_SRCS})
target_link_libraries(mirror ${wxWidgets_LIBRARIES} cpprestsdk::cpprest)
target_include_directories(mirror PRIVATE ${wxWidgets_INCLUDE_DIRS})