using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	public class Path
	{
		public int Length () { return nodes.Count - 1;}
		public void AddNode (Node node) {nodes.Add(node);}
		public void SetPath (List <Node> _nodes) {nodes = _nodes;}
		public List <Node> Nodes() { return nodes;}
		private List <Node> nodes;
	}
}

