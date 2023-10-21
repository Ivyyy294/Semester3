using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	interface GraphSearch
	{
		Path Find (Graph graph, Node start, Node dest);
	}

	public class BreadthFirstSearch : GraphSearch
	{
		public Path Find (Graph graph, Node start, Node dest)
		{
			Dictionary <Node, Node> came_from = GetCameFrom(graph, start, dest);

			List <Node> pathNodes = new List<Node>();
			
			if (came_from.ContainsKey (dest))
			{
				Node current = dest;

				while (current != start)
				{
					pathNodes.Add (current);
					current = came_from[current];
				}
				pathNodes.Add (start);
				pathNodes.Reverse();
			}

			Path path = new Path();
			path.SetPath (pathNodes);

			return path;
		}

		private Dictionary <Node, Node> GetCameFrom (Graph graph, Node start, Node dest)
		{
			Queue <Node> frontier = new Queue<Node>();
			Dictionary <Node, Node> came_from = new Dictionary<Node, Node>();
			frontier.Enqueue (start);
			came_from[start] = null;

			while (frontier.Count > 0)
			{
				Node current = frontier.Dequeue();

				foreach (Node i in graph.Neighbors(current))
				{
					if (!came_from.ContainsKey (i))
					{
						frontier.Enqueue (i);
						came_from[i] = current;
					}
				}
			}

			return came_from;
		}
	}
}
