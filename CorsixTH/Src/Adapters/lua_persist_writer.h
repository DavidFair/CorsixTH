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

#ifndef CORSIXTH_LUA_PERSIST_WRITER_H_
#define CORSIXTH_LUA_PERSIST_WRITER_H_

#include "lua_state_wrapper.h"
#include "persist_lua.h"
#include "virtual_macro.h"

#include <cstdint>

class LuaPersistWriter {
public:
	LuaPersistWriter(lua_persist_writer *writer) : writer(writer) {}

	VIRTUAL_TESTABLE LuaStateWrapper get_stack() const;
	VIRTUAL_TESTABLE void fastWriteStackObject(int iIndex) const;
	VIRTUAL_TESTABLE void writeByteStream(const uint8_t *pBytes, size_t iCount) const;
	VIRTUAL_TESTABLE void writeInt(int val) const;
	VIRTUAL_TESTABLE void writeStackObject(int iIndex) const;
	VIRTUAL_TESTABLE void writeUint(int val) const;
	VIRTUAL_TESTABLE void writeUint(size_t val) const;
	VIRTUAL_TESTABLE void writeUint(uint32_t val) const;

private:
	lua_persist_writer *writer;

};

#endif // !CORSIXTH_LUA_PERSIST_WRITER_H_
