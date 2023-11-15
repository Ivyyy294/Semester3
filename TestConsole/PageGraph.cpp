#include "PageGraph.h"

PageNode& PageGraph::AddNode ()
{
	pages.push_back (PageNode ());
	return pages.back ();
}
