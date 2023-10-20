namespace Graph
{
	public class Node
	{
		//Public
		public Node ()
		{
			degree = 0;
		}

		public bool IsIsolated() { return degree == 0;}

		public uint Degree() {return degree;}
		public void IncreaseDegree() { degree++;}
		public void DecreaseDegree() { degree--;}
		
		//Private
		private uint degree;
	}
}
