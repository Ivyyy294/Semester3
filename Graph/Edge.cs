using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	class Edge
	{
		Edge (Node _n1, Node _n2, float _weight)
		{
			n1 = _n1;
			n2 = _n2;
			weight = _weight;
		}

		private Node n1 = null;
		private Node n2 = null;
		private float weight;
	}
}
