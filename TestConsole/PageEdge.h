#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Inventory.h"
#include "PageNode.h"

class PageEdge
{
public:
	typedef std::shared_ptr <PageEdge> Ptr;
	typedef std::vector <PageEdge::Ptr> Vec;

	typedef bool (Inventory::* ConditionFunc)();

	PageEdge (const std::wstring& _name, PageNode::Ptr _node, ConditionFunc _lockCondition = nullptr, ConditionFunc _visibleCondition = nullptr);
	
	//Get
	inline const std::wstring& GetName () const { return name; }
	inline PageNode::Ptr GetNode () const { return node; }
	bool IsVisible () const;
	bool IsLocked () const;

	//Set
	inline void SetVisibleCondition (ConditionFunc _visibleCondition) { visibleCondition = _visibleCondition; }
	inline void SetLockCondition (ConditionFunc _lockCondition, const std::wstring& msg) { lockCondition = _lockCondition; lockMessage = msg; }

private:
	std::wstring name;
	PageNode::Ptr node;
	ConditionFunc lockCondition { nullptr };
	std::wstring lockMessage;
	ConditionFunc visibleCondition { nullptr };
};

