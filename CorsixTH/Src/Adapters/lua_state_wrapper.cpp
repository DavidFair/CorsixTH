#include "lua_state_wrapper.h"

#include <lua.h>

LuaStateWrapper::LuaStateWrapper(lua_State *existingState) :
	state(existingState) {}
