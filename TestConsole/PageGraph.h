#pragma once
#include "PageNode.h"

class PageGraph
{
public:
	PageNode& AddNode ();

private:
	PageNode::Vec pages;
};

