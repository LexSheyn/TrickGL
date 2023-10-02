cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_C_STANDARD           90) # C89
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS         NO)

project(TrickGL LANGUAGES C)

set(TARGET_NAME ${PROJECT_NAME})

add_compile_definitions(TK_EXPORT=1)

get_filename_component(PROJECT_PARENT_DIRECTORY ${CMAKE_SOURCE_DIR} DIRECTORY)

# Directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_DEPENDENCY_DIR         ${CMAKE_SOURCE_DIR}/dependencies)
#

# Dependencies
file(GLOB_RECURSE OPENGL_HEADERS "${PROJECT_DEPENDENCY_DIR}/OpenGL/include/*.h")
if (WIN32)
file(GLOB_RECURSE OPENGL_LIB     "${PROJECT_DEPENDENCY_DIR}/OpenGL/lib/*.lib")
elseif (UNIX)
file(GLOB_RECURSE OPENGL_LIB     "${PROJECT_DEPENDENCY_DIR}/OpenGL/lib/*.so")
endif()
#

# Source code
file(GLOB_RECURSE PROJECT_HEADERS "include/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "source/*.c")
#

add_library(${TARGET_NAME} SHARED)

target_sources(${TARGET_NAME} PUBLIC
               ${PROJECT_HEADERS}
               ${PROJECT_SOURCES}
               ${OPENGL_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC
                           "include"
                           "${PROJECT_DEPENDENCY_DIR}/OpenGL/include")

target_link_libraries(${TARGET_NAME} PUBLIC
                      ${OPENGL_LIB})
