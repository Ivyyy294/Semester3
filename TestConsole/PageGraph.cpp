#include "PageGraph.h"

PageNode::Ptr PageGraph::AddNode ()
{
	PageNode::Ptr node = std::make_shared <PageNode> ();
	nodes.emplace_back (node);
	return node;
}
//
//PageEdge::Ptr PageGraph::AddEdge (PageNode::Ptr nodeFrom, PageNode::Ptr nodeTo, const std::wstring& name)
//{
//	for (auto& i : data)
//	{
//		if (i.first == nodeFrom)
//		{
//			PageEdge::Ptr ptr (new PageEdge (name, nodeTo));
//			i.second.push_back (ptr);
//		}
//	}
//}
//
//PageEdge::Vec PageGraph::GetEdges (PageNode::Ptr node) const
//{
//	for (const auto& i : data)
//	{
//		if (i.first == node)
//			return i.second;
//	}
//
//	return PageEdge::Vec ();
//}
