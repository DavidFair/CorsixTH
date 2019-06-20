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

find_package(Catch2 CONFIG REQUIRED)
find_package(Trompeloeil REQUIRED)

add_custom_target(AllTests)

# Expose the header files from CorsixTH
include_directories(${CMAKE_SOURCE_DIR}/CorsixTH/Src/)
include_directories(${Trompeloeil_INCLUDE_DIR})

add_executable(UnitTests "")
target_link_libraries(UnitTests Catch2::Catch2)
target_link_libraries(UnitTests CorsixTH_lib)

set_property(TARGET UnitTests PROPERTY CXX_STANDARD 14)
set_property(TARGET UnitTests PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET UnitTests PROPERTY CXX_STANDARD_REQUIRED ON)

# Add the target to CTest
add_test(NAME UnitTests COMMAND UnitTests)
add_dependencies(UnitTests trompeloeil)
# Make sure we add it as a dependency to all tests (some day we can add LuaTest here)
add_dependencies(AllTests UnitTests)

# Ensure virtuals are correctly marked
target_compile_definitions(CorsixTH_lib PUBLIC TESTING=1)

set_target_properties(UnitTests PROPERTIES FOLDER tests)

# List of all test files
target_sources(UnitTests
    PRIVATE
    # Main entry point
    ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp

    # Mock instances
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter_mock.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader_mock.h

    # Unit test definitions
    ${CMAKE_CURRENT_SOURCE_DIR}/th_gfx_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/th_gfx_sdl_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/th_lua_anims_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/th_map_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/th_test.cpp
)
