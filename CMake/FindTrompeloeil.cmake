# MIT License
# 
# Copyright (c) 2019 David Fairbrother
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if(NOT EXISTS "${Trompeloeil_INCLUDE_DIR}")
     find_path(Trompeloeil_INCLUDE_DIR
         NAMES catch2/trompeloeil.hpp.hpp 
         DOC "Trompeloeil library header files"
     )
endif()

if(EXISTS "${Trompeloeil_INCLUDE_DIR}")
  include(FindPackageHandleStandardArgs)
  mark_as_advanced(Trompeloeil_INCLUDE_DIR)
else()
  include(ExternalProject)
  ExternalProject_Add(trompeloeil
    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_SHALLOW 1
    TIMEOUT 5
    CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    PREFIX "${CMAKE_BINARY_DIR}/ext"
    INSTALL_COMMAND ""
    )

  # Specify include dir
  ExternalProject_Get_Property(trompeloeil source_dir)
  set(Trompeloeil_INCLUDE_DIR ${source_dir}/include/catch2)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(trompeloeil PROPERTIES FOLDER ext)

if(EXISTS "${Trompeloeil_INCLUDE_DIR}")
  set(Trompeloeil_FOUND 1)
else()
  set(Trompeloeil_FOUND 0)
endif()