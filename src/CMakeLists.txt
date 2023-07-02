project(rooks-walks)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

option(ENABLE_THREAD_SANITIZER "Enable thread sanitizer" OFF)

find_package(Threads)

set(TARGET ${PROJECT_NAME})

set (WILDCARD_SOURCE *.cpp)

file(GLOB_RECURSE SOURCES ${WILDCARD_SOURCE})

add_executable(
  ${TARGET}
    ${SOURCES}
)

target_link_libraries(
  ${TARGET}
    ${CMAKE_THREAD_LIBS_INIT}
)

if (ENABLE_THREAD_SANITIZER)
  target_compile_options(${TARGET} PRIVATE -fsanitize=thread)
  target_link_options(${TARGET} PRIVATE -fsanitize=thread)

  message(STATUS "Thread Sanitizer enabled")
endif()
