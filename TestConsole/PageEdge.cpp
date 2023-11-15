#include "PageEdge.h"
#include "PageNode.h"

PageEdge::PageEdge (const PageNode& _node, ConditionFunc _lockCondition, ConditionFunc _visibleCondition)
	: node (_node)
	, lockCondition (_lockCondition)
	, visibleCondition (_visibleCondition)
{
}

bool PageEdge::IsVisible () const
{
	if (lockCondition != nullptr)
		return (&Inventory::Me ()->*visibleCondition)();

	return false;
}

bool PageEdge::IsLocked () const
{
	if (lockCondition != nullptr)
		return (&Inventory::Me ()->*lockCondition)();

	return false;
}
