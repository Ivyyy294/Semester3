namespace Graph
{
	public class Edge
	{
		//Public
		public Edge (Node n1, Node n2, float _weight = 1f)
		{
			nodes = new Node[2] {n1, n2 };
			nodes[0].IncreaseDegree();
			nodes[1].IncreaseDegree();
			weight = _weight;
		}

		public bool IsSelfLoop ()
		{
			return nodes[0] == nodes[1];
		}

		public Node[] GetNodes()
		{
			return nodes;
		}

		public bool ContainsNode (Node node)
		{
			return nodes[0] == node || nodes[1] == node;
		}

		//Private
		~Edge ()
		{
			nodes[0].DecreaseDegree();
			nodes[1].DecreaseDegree();
		}

		private Node[] nodes = null;
		private float weight;
	}
}
