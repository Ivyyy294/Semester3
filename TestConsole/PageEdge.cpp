#include "PageEdge.h"
#include "PageNode.h"

PageEdge::PageEdge (const std::wstring& _name, PageNode::Ptr _node, ConditionFunc _lockCondition, ConditionFunc _visibleCondition)
	: name (_name)
	, node (_node)
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
