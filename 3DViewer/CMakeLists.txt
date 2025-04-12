cmake_minimum_required(VERSION 3.10)
project(3DViewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Suppress OpenGL deprecation warnings
add_definitions(-DGL_SILENCE_DEPRECATION)

# Set Assimp directory for macOS
if(APPLE)
    set(ASSIMP_DIR "/opt/homebrew/opt/assimp")
    set(ASSIMP_INCLUDE_DIRS "${ASSIMP_DIR}/include")
    set(ASSIMP_LIBRARIES "${ASSIMP_DIR}/lib/libassimp.dylib")
endif()

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(assimp REQUIRED)

# Include directories
include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLFW3_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

# Add source files
set(SOURCES
    src/main.cpp
    src/Application.cpp
    src/Model.cpp
    src/Shader.cpp
    src/FileDialog.mm
    src/Texture2D.cpp
    src/Image2D.cpp
)

# Enable Objective-C++
if(APPLE)
    set_source_files_properties(src/FileDialog.mm PROPERTIES COMPILE_FLAGS "-x objective-c++")
endif()

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${OPENGL_LIBRARIES}
    glfw
    ${ASSIMP_LIBRARIES}
)

# Add OpenGL framework on macOS
if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL" "-framework Cocoa")
endif()

# Copy resources to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders ${CMAKE_BINARY_DIR}/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/models ${CMAKE_BINARY_DIR}/models
) 