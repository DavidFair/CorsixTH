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

#include "catch2\catch.hpp"
#include "trompeloeil.hpp"

#include "lua_adapter_mock.h"
#include "lua_state_wrapper_mock.h"
#include "lua_persist_reader_mock.h"
#include "th_gfx.h"

TEST_CASE("depersist", "[th_gfx]") {
	animation instance;
	LuaStateWrapperMock mockState;

	SECTION("depersist exits on bad lua stack read") {
		PersistReaderMock mockedReader;

		REQUIRE_CALL(mockedReader, get_stack()).RETURN(mockState);
		
		REQUIRE_CALL(mockedReader, read_stack_object()).RETURN(false);
		REQUIRE_CALL(mockedReader, set_error(ANY(const char*)));

		instance.depersist(mockedReader);
	}

	SECTION("depersist exits if flags can't be read") {
		PersistReaderMock mockedReader;

		REQUIRE_CALL(mockedReader, get_stack()).RETURN(mockState);
		REQUIRE_CALL(mockedReader, read_stack_object()).RETURN(true);

		REQUIRE_CALL(mockedReader, read_uint(ANY(uint32_t&))).RETURN(false);
		REQUIRE_CALL(mockedReader, set_error(ANY(const char*)));

		instance.depersist(mockedReader);
	}
	

	
}