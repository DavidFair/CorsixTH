
target_sources(CorsixTH_lib
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.h

)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})