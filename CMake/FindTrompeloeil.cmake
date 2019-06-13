
# Allow the user can specify the include directory manually:
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
    GIT_SHALLOW true
    TIMEOUT 5
    CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
    PREFIX "${CMAKE_BINARY_DIR}/ext"
    INSTALL_COMMAND ""
    )

  # Specify include dir
  ExternalProject_Get_Property(trompeloeil source_dir)
  set(Trompeloeil_INCLUDE_DIR ${source_dir}/include/catch2)
endif()

message("Here")
if(EXISTS "${Trompeloeil_INCLUDE_DIR}")
  message(${Trompeloeil_INCLUDE_DIR})
  set(Trompeloeil_FOUND 1)
else()
  message("Not Found")
  set(Trompeloeil_FOUND 0)
endif()