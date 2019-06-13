// MIT License
// 
// Copyright(c) 2019 David Fairbrother
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef CORSIXTH_LUA_ADAPTER_MOCK_H_
#define CORSIXTH_LUA_ADAPTER_MOCK_H_

#include "Adapters/lua_adapter.h"
#include "trompeloeil.hpp"

class LuaAdapterMock : public LuaAdapter {
	MAKE_CONST_MOCK2(pop, void(lua_State *L, int idx), override);
	MAKE_CONST_MOCK2(toUserData, void*(lua_State *L, int idx), override);
	
};

#endif // CORSIXTH_LUA_ADAPTER_MOCK_H_