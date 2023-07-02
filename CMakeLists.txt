cmake_minimum_required(VERSION 3.16)

project(multithreaded-rooks-walks)

set(
  CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib
  CACHE
    INTERNAL "Directory where all .lib|.a files are dumped."
)

set(
  CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib
  CACHE
    PATH "Directory where all .so files are dumped."
)

set(
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
  CACHE
  PATH "Directory where all executable files (including .dll files for DLL-platforms) are dumped."
)

add_subdirectory(src)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")