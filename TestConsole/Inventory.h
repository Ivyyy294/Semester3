#pragma once
class Inventory
{
public:
	inline static Inventory& Me () { return me; };

private:
	static Inventory me;
};

