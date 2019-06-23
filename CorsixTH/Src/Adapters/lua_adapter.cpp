#include "lua_adapter.h"
#include "lua_state_wrapper.h"
#include "th_lua.h"

/// Static instantiation
LuaAdapter LuaAdapter::adapterInstance;

void LuaAdapter::getEnvField(LuaStateWrapper & L, int index, const char * k) const
{
	return luaT_getenvfield(L.get(), index, k);
}

void LuaAdapter::pop(LuaStateWrapper &L, int idx) const
{
	return lua_pop(L.get(), idx);
}

void LuaAdapter::pushLightUserData(LuaStateWrapper & L, void * p) const
{
	return lua_pushlightuserdata(L.get(), p);
}

int LuaAdapter::rawGet(LuaStateWrapper & L, int idx) const
{
	return lua_rawget(L.get(), idx);
}

int LuaAdapter::rawGetI(LuaStateWrapper & L, int idx, lua_Integer n) const
{
	return lua_rawgeti(L.get(), idx, n);
}

const char * LuaAdapter::pushfString(LuaStateWrapper & L, const char * fmt, int i) const
{
	return lua_pushfstring(L.get(), fmt, i);
}

void * LuaAdapter::toUserData(LuaStateWrapper &L, int idx) const
{
	return lua_touserdata(L.get(), idx);
}

LuaAdapter& LuaAdapter::getAdapter() noexcept
{
	return LuaAdapter::adapterInstance;
}

void LuaAdapter::setAdapter(LuaAdapter && newAdapter) noexcept
{
	LuaAdapter::adapterInstance = newAdapter;
}