#include "lua_persist_reader.h"
#include "lua_state_wrapper.h"

#include <stdint.h>


LuaStateWrapper LuaPersistReader::get_stack()
{
	return LuaStateWrapper(reader->get_stack());
}

bool LuaPersistReader::read_stack_object()
{
	return reader->read_stack_object();
}

bool LuaPersistReader::read_byte_stream(uint8_t * pBytes, size_t iCount)
{
	return reader->read_byte_stream(pBytes, iCount);
}

bool LuaPersistReader::read_int(int & i)
{
	return reader->read_int(i);
}

bool LuaPersistReader::read_uint(uint32_t & i)
{
	return reader->read_uint(i);
}

bool LuaPersistReader::read_uint(size_t & i)
{
	return reader->read_uint(i);
}

bool LuaPersistReader::read_uint(int & i)
{
	return reader->read_uint(i);
}

void LuaPersistReader::set_error(const char * err)
{
	return reader->set_error(err);
}
