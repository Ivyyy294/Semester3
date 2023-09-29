using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
	public class Page
	{
		//static public void ShowPage (byte pageNr)
		//{
		//	if (pageMap.ContainsKey(pageNr))
		//		pageMap[pageNr].Run();
		//	else
		//	{
		//		Console.Clear();
		//		Console.WriteLine("ERROR: Page " + pageNr.ToString() + " not found!");
		//		Console.ReadLine();
		//	}
		//}

		private bool historie = true;
		private bool goBackPossible = true;
		private string content = "";
		private Action decoration = null;
		private Action action = null;
		private byte pageId;
		private Stack <Answer> answers = new Stack <Answer> ();

		public Page (byte id)
		{
			pageId = id;
		}

		public void SetHistorie(bool val) { historie = val; }
		public bool GetHistorie() { return historie; }
		public byte GetPageId () { return pageId; }
		//public void SetGoBackPossible(bool val) { goBackPossible = val; }
		public void SetAction (Action a) { action = a; }
		public void SetContent (string c) {content = c;}
		public void SetDecoration (Action a) {decoration = a;}
		public void AddAnswer (Answer a) {answers.Push(a);}
		public void AddAnswer(string text, byte pageNr) { answers.Push(new Answer(text, pageNr)); }
		public Stack <Answer> GetAnswers() { return answers;}
		public void Action()
		{
			if (action != null)
				action();
		}
		public void Draw()
		{
			Console.Clear();

			Console.WriteLine("\n\n");

			if (decoration != null)
				decoration();

			Console.WriteLine("");

			Drawings.DrawCenterTextLine (content);
		}
		public bool GoBackPossible() { return goBackPossible;}
	}
}
