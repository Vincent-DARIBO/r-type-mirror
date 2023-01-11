project(bomberman)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
cmake_minimum_required(VERSION 3.17)

#install threads lib
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Install alsa
if(UNIX)
  find_package(ALSA)
  find_package(MESA)
  if (NOT X11_FOUND)
  find_library(X11_X11_LIB X11               ${X11_LIB_SEARCH_PATH})
  endif()
endif(UNIX)

# Install raylib
if(NOT raylib_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
  FetchContent_GetProperties(raylib)

  if(NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

# target_link_librairies
if(UNIX)
  add_compile_options(-Wall -g3 -std=c++20)
endif(UNIX)

# add_compile_options(-Wall -lstdc++fs -std=c++20 -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -g3)
# Compile with CFLAGS

# Set Include Directory
include_directories(inc)

# Set Cmake Wildcard
file(COPY sprites DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB ALL_SRCS
  # "src/*. "
  "src/Components/*.cpp"
  # "src/screens/*.cpp"
  # "src/Raylib/*.cpp"
)

# Set Sources Files & Link Libraries
add_executable(bomberman ${ALL_SRCS})
target_link_libraries(bomberman Threads::Threads  "raylib")
