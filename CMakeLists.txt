cmake_minimum_required(VERSION 3.21.0)
project (Minecraft)

add_subdirectory(extern)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_23)

target_link_libraries(main OpenGL::GL glfw glm glad rapidjson stb)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)