using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	struct Position
	{
		float x;
		float y;
	}

	class Node
	{
		public Node (string _name, Position _pos)
		{
			name = _name;
			pos = _pos;
		}

		private string name;
		private Position pos;

		string GetName () { return name;}
		Position GetPosition() { return pos;}
	}
}
