#include "lua_adapter.h"
#include "th_lua.h"

LuaAdapter LuaAdapter::adapterInstance;

void LuaAdapter::pop(lua_State *L, int idx) const
{
	lua_pop(L, 1);
}

void * LuaAdapter::toUserData(lua_State *L, int idx) const
{
	return lua_touserdata(L, idx);
}


LuaAdapter& LuaAdapter::getAdapter() noexcept
{
	return LuaAdapter::adapterInstance;
}

void LuaAdapter::setAdapter(LuaAdapter && newAdapter) noexcept
{
	LuaAdapter::adapterInstance = newAdapter;
}