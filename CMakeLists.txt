cmake_minimum_required(VERSION 3.0.0)
project(mini)

set(CMAKE_CXX_STANDARD 17)

set(code 
    src/Main.cpp
    src/Game.cpp
    src/Player.cpp

    src/glad.c
    src/std_image.cpp
)
add_executable(mini ${code})
include_directories(mini include include/engine)

find_package(OpenGL REQUIRED)
target_link_libraries(mini OpenGL::GL)

find_package(SDL2 REQUIRED)
include_directories(mini ${SDL2_INCLUDE_DIRS})
target_link_libraries(mini ${SDL2_LIBRARIES})