namespace Graph
{
	public struct Position
	{
		public Position (float _x, float _y)
		{
			x = _x;
			y = _y;
		}

		public float x;
		public float y;
	}

	public class PositionNode : Node
	{
		//Public
		public PositionNode (string _name, Position _pos)
		{
			name = _name;
			pos = _pos;
		}
	
		public string GetName () { return name;}
		public Position GetPosition() { return pos;}

		//Private
		private string name;
		private Position pos;
	}
}
