#include "lua_persist_writer.h"

LuaStateWrapper LuaPersistWriter::get_stack() const
{
	return writer->get_stack();
}

void LuaPersistWriter::fastWriteStackObject(int iIndex) const
{
	return writer->fast_write_stack_object(iIndex);
}

void LuaPersistWriter::writeByteStream(const uint8_t * pBytes, size_t iCount) const
{
	return writer->write_byte_stream(pBytes, iCount);
}

void LuaPersistWriter::writeInt(int val) const
{
	return writer->write_int(val);
}

void LuaPersistWriter::writeStackObject(int iIndex) const
{
	return writer->write_stack_object(iIndex);
}

void LuaPersistWriter::writeUint(int val) const
{
	return writer->write_uint(val);
}

void LuaPersistWriter::writeUint(size_t val) const
{
	return writer->write_uint(val);
}

void LuaPersistWriter::writeUint(uint32_t val) const
{
	return writer->write_uint(val);
}
