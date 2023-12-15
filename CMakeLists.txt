# установи все зависимости:
# sudo apt install libglew-dev libglfw3-dev libglm-dev

cmake_minimum_required(VERSION 3.16)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

aux_source_directory(./src SRCS)

add_executable(Engine ${SRCS})

find_package(OpenGL)
target_link_libraries(Engine OpenGL)

find_package(GLEW)
target_link_libraries(Engine GLEW)

find_package(glfw3)
target_link_libraries(Engine glfw)

find_package(glm)
