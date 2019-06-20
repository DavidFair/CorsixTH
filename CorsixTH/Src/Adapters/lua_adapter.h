/*
Copyright (c) 2019 David Fairbrother

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CORSIXTH_LUA_ADAPTER_H_
#define CORSIXTH_LUA_ADAPTER_H_

#include "th_lua.h"
#include "virtual_macro.h"

/**
 * A simple adapter which directly translates all calls to the Lua
 * API layer with no side effects. This can be derived from to provide
 * a mocking or fake injection point
 */
class LuaAdapter {
public:
	LuaAdapter() = default;

	// Mocked Lua API methods
	VIRTUAL_TESTABLE void pop(lua_State *L, int idx) const;
	VIRTUAL_TESTABLE void* toUserData(lua_State *L, int idx) const;

	static LuaAdapter& getAdapter() noexcept;
	static void setAdapter(LuaAdapter &&newAdapter) noexcept;
private:
	static LuaAdapter adapterInstance;
};

#endif //CORSIXTH_LUA_ADAPTER_H_