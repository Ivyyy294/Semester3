using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	public class Graph
	{
		//Public
		public Graph()
		{
			edges = new List<Edge>();
			nodes = new List<Node>();
		}

		public List <Edge> Edges() {return edges;}

		public List <Node> Nodes() {return nodes;}

		public void AddNode (Node node) { nodes.Add (node);}

		public void RemoveNode (Node node)
		{
			foreach (Edge i in GetEdgesToNode (node))
				RemoveEdge (i);

			nodes.Remove (node);
		}

		public void AddEdge (Node n1, Node n2) { edges.Add (new Edge (n1, n2));}

		public void AddEdge (Edge edge) { edges.Add (edge);}

		public void RemoveEdge (Edge e)
		{
			edges.Remove (e);
		}

		public List <Edge> GetEdgesToNode (Node node)
		{
			List <Edge> nodeEdges = new List<Edge>();

			foreach (Edge i in edges)
			{
				if (i.ContainsNode(node))
					nodeEdges.Add (i);
			}

			return nodeEdges;
		}

		public Edge GetEdge (Node n1, Node n2)
		{
			foreach (Edge i in edges)
			{
				if (i.ContainsNode (n1) && i.ContainsNode (n2))
					return i;
			}

			return null;
		}

		public List<Node> Neighbors (Node node)
		{
			List <Node> neighbors = new List<Node>();

			foreach (Edge i in GetEdgesToNode (node))
			{
				foreach (Node j in i.GetNodes())
				{
					if (j != node && !neighbors.Contains (j))
						neighbors.Add (j);
				}
			}

			return neighbors;
		}

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
