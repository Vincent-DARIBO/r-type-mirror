project(r-type)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
cmake_minimum_required(VERSION 3.17)

# install threads lib
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(UNIX)
  INCLUDE(FetchContent)

  # install glfw lib -> https://jonathanhamberg.com/post/2019-01-27-cmake-dependencies-fetch-content/
  find_package(OpenGL)

  if(NOT OPENGL_FOUND)
    message("**did not find open gl, downloading...**")
  endif()

  # install xrandr lib
  find_package(ALSA)
  find_package(X11)

  if(NOT X11_FOUND)
    message("**did not find x11**")
  else()
    message("**x11 found **")
  endif()

  if(NOT X11_Xrandr_FOUND)
    message("**did not find xrandr library**")
    FetchContent_Declare(
      xrandr
      GIT_REPOSITORY https://github.com/freedesktop/xorg-xrandr
    )

    FetchContent_GetProperties(xrandr)

    if(NOT xrandr_POPULATED)
      FetchContent_Populate(xrandr)

      add_subdirectory(${xrandr_SOURCE_DIR} ${xrandr_BINARY_DIR})
    endif()
  else()
    message("**x11 lixrandr found**")
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
  add_compile_options(-Wall -lstdc++fs -std=c++20 -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -g3)
endif(UNIX)

# Insatll boost asio
SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost 1.42.0 REQUIRED COMPONENTS system thread regex)

if(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
else()
  message("**did not find boost asio**")
endif(Boost_FOUND)

SET(boost_lib ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

# Compile with CFLAG
# add_compile_options(-Wall -lstdc++fs -std=c++20 -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -g3)

# Set Include Directory
include_directories(inc)

# Set Cmake Wildcard
file(COPY sprites DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB ALL_SRCS
  "./*.cpp"
  # "Builders/*.cpp"
  "Factory/*.cpp"
  "Components/*.cpp"
  "Entity/*.cpp"
  "System/*.cpp"
)

# Set Sources Files & Link Libraries
add_executable(${PROJECT_NAME} ${ALL_SRCS})
target_link_libraries(${PROJECT_NAME} Threads::Threads  "raylib" ${boost_lib})
