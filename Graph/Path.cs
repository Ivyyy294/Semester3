using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	class Path
	{
		public int Length () { return edges.Count;}
		public void AddEdge (Edge edge) {edges.Add(edge);}
		private List <Edge> edges;
	}
}

