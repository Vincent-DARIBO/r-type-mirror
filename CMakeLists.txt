project(r-type)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
cmake_minimum_required(VERSION 3.17)

# install threads lib
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

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


# Insatll boost asio
find_package(Boost COMPONENTS system thread regex asio)

if(NOT BOOST_asio_FOUND)
  INCLUDE(FetchContent)
  message("**COULD NOT FIND ASIO**")

  if(UNIX)
    FetchContent_Declare(asio URL https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz)
    FetchContent_GetProperties(asio)
  elseif(WIN32)
    FetchContent_Declare(asio URL https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.zip)
    FetchContent_GetProperties(asio)

    # linux -> https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
    # windows -> https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.zip
  endif()

  if(NOT asio_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(asio)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    # ADD_SUBDIRECTORY(${asio_SOURCE_DIR} ${asio_BINARY_DIR})
    SET(asio_FOUND TRUE)
  endif()
endif()

# target_link_librairies
if(UNIX)
  add_compile_options(-Wall -lstdc++fs -std=c++20 -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -g3)
endif(UNIX)

# Compile with CFLAG
# add_compile_options(-Wall -lstdc++fs -std=c++20 -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -g3)

set(lib_asio ${CMAKE_BINARY_DIR}/asio-src/boost)
# Set Include Directory
include_directories(inc lib_asio)

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
SET(boost_required_libs ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
add_executable(${PROJECT_NAME} ${ALL_SRCS})
target_link_libraries(${PROJECT_NAME} Threads::Threads "raylib" ${boost_required_libs})
