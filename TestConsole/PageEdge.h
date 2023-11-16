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
	inline const std::wstring& GetLockMessage () const { return lockMessage; }
	bool IsVisible () const;
	bool CheckCondition () const;

	//Set
	inline void SetVisibleCondition (ConditionFunc _visibleCondition) { visibleCondition = _visibleCondition; }
	inline void SetCondition (ConditionFunc _condition, const std::wstring& msg) { condition = _condition; lockMessage = msg; }

private:
	std::wstring name;
	PageNode::Ptr node;
	ConditionFunc condition { nullptr };
	std::wstring lockMessage;
	ConditionFunc visibleCondition { nullptr };
};

