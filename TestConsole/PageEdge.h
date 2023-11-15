#pragma once
#include <vector>
#include "Inventory.h"

//Forward declaration to avoid include dead loop
class PageNode;

class PageEdge
{
public:
	typedef std::vector <PageEdge> Vec;
	typedef bool (Inventory::* ConditionFunc)();

	PageEdge (const PageNode& _node, ConditionFunc _lockCondition = nullptr, ConditionFunc _visibleCondition = nullptr);
	
	inline const PageNode& GetNode () const { return node; }
	bool IsVisible () const;
	bool IsLocked () const;

private:
	const PageNode& node;
	ConditionFunc lockCondition { nullptr };
	ConditionFunc visibleCondition { nullptr };
};

