using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph
{
	class Program
	{
		static void Main(string[] args)
		{
			Graph cityGraph = new Graph();

			//Init Nodes
			PositionNode aachen = new PositionNode ("Aachen", new Position(0f, 0f));
			PositionNode juelich = new PositionNode ("Jülich", new Position(1f, 1f));
			PositionNode wuerselen = new PositionNode ("Würselen", new Position(2f, 2f));
			PositionNode herzogenrath = new PositionNode ("Herzogenrath", new Position(3f, 3f));
			PositionNode krefeld = new PositionNode ("Krefeld", new Position(4f, 4f));
			PositionNode koeln = new PositionNode ("Köln", new Position(5f, 5f));
			PositionNode duesseldorf = new PositionNode ("Düsseldorf", new Position(6f, 6f));

			//Add Nodes
			cityGraph.AddNode (aachen);
			cityGraph.AddNode (juelich);
			cityGraph.AddNode (wuerselen);
			cityGraph.AddNode (herzogenrath);
			cityGraph.AddNode (krefeld);
			cityGraph.AddNode (koeln);

			//Init Edges
			cityGraph.AddEdge (aachen, herzogenrath);
			cityGraph.AddEdge (aachen, wuerselen);
			cityGraph.AddEdge (herzogenrath, wuerselen);
			cityGraph.AddEdge (wuerselen, juelich);
			cityGraph.AddEdge (wuerselen, koeln);
			cityGraph.AddEdge (juelich, koeln);
			cityGraph.AddEdge (juelich, krefeld);
			cityGraph.AddEdge (krefeld, duesseldorf);
			cityGraph.AddEdge (koeln, duesseldorf);
		}
	}
}
