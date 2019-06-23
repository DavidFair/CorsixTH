
set(CorsixTH_lib_adapters
    ${CMAKE_CURRENT_SOURCE_DIR}/virtual_macro.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_adapter.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_reader.h

    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_writer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_persist_writer.h
    
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_state_wrapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lua_state_wrapper.h
)

target_sources(CorsixTH_lib PRIVATE ${CorsixTH_lib_adapters})
target_include_directories(CorsixTH_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
