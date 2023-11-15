#include "PageNode.h"

inline void PageNode::AddEdge (const PageEdge& edge)
{
	edges.push_back (edge);
}
