#pragma once

#include <memory>

class NetObj
{
public:
	virtual ~NetObj() = default;
	virtual void func2() {}
	virtual char get_object_type() { return 0; }
	virtual void update_object() {}

	/* 0x0008 */ char pad_0x8[0x8];
	/* 0x0010 */ std::shared_ptr<NetObj> self_ptr;
	/* 0x0020 */ __int32 id;
	/* 0x0024 */ __int32 m_iRevision;

}; // Size: 0x28

static_assert(sizeof(NetObj) == 0x28, "NetObj: Incorrect Size");