# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-src"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-build"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/tmp"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/src"
  "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/taniabzn/Documents/Epitech/Tek3/R-type/B-CPP-500-LYN-5-2-rtype-tania.bezancon/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
