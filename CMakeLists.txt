cmake_minimum_required(VERSION 3.21.0)
project (Minecraft)
set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS "-g -pthread")

file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(main ${SOURCES})

set(GLEW "glew32")
set(GLFW "glfw3")
set(OPENGL "opengl32")
target_link_libraries(main ${GLEW})
target_link_libraries(main ${GLFW})
target_link_libraries(main ${OPENGL})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)