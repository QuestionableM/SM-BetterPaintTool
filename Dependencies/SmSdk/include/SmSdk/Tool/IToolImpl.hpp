#pragma once

struct IToolImpl
{
	virtual void func1() {};
	virtual void func2() {};
	virtual void func3() {};
	virtual void func4() {};
	virtual void func5() {};
	virtual void func6() {};
	virtual bool is_equipped() { return false; };

}; // Size: 0x8

static_assert(sizeof(IToolImpl) == 0x8, "IToolImpl: Incorrect Size");