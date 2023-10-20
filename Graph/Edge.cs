namespace Graph
{
	class Edge
	{
		//Public
		public Edge (Node _n1, Node _n2)
		{
			AddNode (_n1, n1);
			AddNode (_n2, n2);
			weight = 1f;
		}

		public Edge (Node _n1, Node _n2, float _weight)
		{
			AddNode (_n1, n1);
			AddNode (_n2, n2);
			weight = _weight;
		}

		~Edge ()
		{
			n1.DecreaseDegree();
			n2.DecreaseDegree();
		}

		//Private
		private Node n1 = null;
		private Node n2 = null;
		private float weight;

		private void AddNode (Node srcNode, Node targetNode)
		{
			targetNode = srcNode;
			targetNode.IncreaseDegree();
		}
	}
}
