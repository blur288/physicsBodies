# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-src"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-build"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/tmp"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/src/ldtkloader-populate-stamp"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/src"
  "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/src/ldtkloader-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/src/ldtkloader-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/_deps/ldtkloader-subbuild/ldtkloader-populate-prefix/src/ldtkloader-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
