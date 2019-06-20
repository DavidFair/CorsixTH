
set(CorsixTH_lib_adapters
    ${CMAKE_CURRENT_SOURCE_DIR}/virtual_macro.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.h
)

target_sources(CorsixTH_lib PRIVATE ${CorsixTH_lib_adapters})
target_include_directories(CorsixTH_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
