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

#ifndef CORSIXTH_LUA_PERSIST_READER_H_
#define CORSIXTH_LUA_PERSIST_READER_H_

#include "persist_lua.h"
#include <stdint.h>

class LuaPersistReader {
public:
	LuaPersistReader(lua_persist_reader *reader) : reader(reader) {}

	virtual lua_State* get_stack();
	virtual bool read_stack_object();
	
	virtual bool read_byte_stream(uint8_t *pBytes, size_t iCount);

	// This was originally templated so we must deal with each type manually
	// to allow mocking
	virtual bool read_int(int &i);
	virtual bool read_uint(int &i);
	virtual bool read_uint(uint32_t &i);
	virtual bool read_uint(size_t &i);

	virtual void set_error(const char *err);

private:
	lua_persist_reader *reader;

};

#endif // !CORSIXTH_LUA_PERSIST_READER_ADAPTER_H_
