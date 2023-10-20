using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
	class Program
	{
		static void Main(string[] args)
		{
			ArrayStorage arrayTest = new ArrayStorage();

			arrayTest.PushEntry ("Lara");
			arrayTest.PushEntry ("Felix");
			arrayTest.PushEntry ("Efe");
			arrayTest.InsertEntry (2, "Carlos");
			arrayTest.RemoveEntry (2);

			foreach (var i in arrayTest.GetSortedList())
				Console.WriteLine (i);

			ListStorage listTest = new ListStorage();
			listTest.PushEntry ("Lara");
			listTest.PushEntry ("Felix");
			listTest.PushEntry ("Efe");
			listTest.InsertEntry (2, "Carlos");
			listTest.RemoveEntry (2);

			foreach (var i in listTest.GetSortedList())
				Console.WriteLine (i);

			MapStorage mapTest = new MapStorage();
			mapTest.PushEntry ("Lara");
			mapTest.PushEntry ("Felix");
			mapTest.PushEntry ("Efe");
			mapTest.InsertEntry (2, "Carlos");
			mapTest.RemoveEntry (2);

			foreach (var i in mapTest.GetSortedList())
				Console.WriteLine (i);

		}
	}
}
