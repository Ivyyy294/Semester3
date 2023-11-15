#pragma once

#include "PageNode.h"

class PageGraph
{
public:
	PageNode::Ptr AddNode ();
	//PageEdge::Ptr AddEdge (PageNode::Ptr nodeFrom, PageNode::Ptr nodeTo, const std::wstring& name);

	//inline PageEdge::Vec GetEdges (PageNode::Ptr node) const;
private:
	PageNode::Vec nodes;
	//typedef std::pair <PageNode::Ptr, PageEdge::Vec> PageEdgePair;

	//std::vector <PageEdgePair> data;
};

