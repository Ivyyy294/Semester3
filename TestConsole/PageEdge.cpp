#include "PageEdge.h"
#include "PageNode.h"

PageEdge::PageEdge (const std::wstring& _name, PageNode::Ptr _node, ConditionFunc _condition, ConditionFunc _visibleCondition)
	: name (_name)
	, node (_node)
	, condition (_condition)
	, visibleCondition (_visibleCondition)
{
}

bool PageEdge::IsVisible () const
{
	if (visibleCondition != nullptr)
		return (Inventory::Me ().*visibleCondition)();

	return true;
}

bool PageEdge::CheckCondition () const
{
	if (condition != nullptr)
	{
		Inventory& instance = Inventory::Me ();
		return (instance.*condition)();
	}

	return true;
}
