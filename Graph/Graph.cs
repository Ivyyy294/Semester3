using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	class Graph
	{
		//Public
		public void AddNode (Node node) { nodes.Add (node);}
		public void AddEdge (Node n1, Node n2) { edges.Add (new Edge (n1, n2));}
		public void AddEdge (Edge edge) { edges.Add (edge);}

		public bool IsComplete()
		{
			//Graph is not complete when it contains a self loop
			if (ContainsSelfLoop())
				return false;

			int nCount = nodes.Count();
			bool complete = edges.Count() == (nCount - 1) * nCount;

			return complete;
		}

		//Returns min length between start and dest
		//public uint Distance (Node start, Node dest)
		//{
		//	return 0;
		//}

		//Private
		private List <Node> nodes;
		private List <Edge> edges;

		private bool ContainsSelfLoop()
		{
			foreach (Edge i in edges)
			{
				if (i.IsSelfLoop())
					return true;
			}

			return false;
		}
	}
}
