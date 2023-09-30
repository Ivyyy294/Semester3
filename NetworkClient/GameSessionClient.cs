using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EscapeFromMedinaStation;
using System.Net.Sockets;

namespace NetworkClient
{
	class GameSessionClient : GameSession
	{
		public GameSessionClient (Socket _socket)
			: base (_socket)
		{
		}

		public override void Frame()
		{
			Page currentPage = GetCurrentPage();

			//Draw Content
			currentPage.Draw();

			//Draw available answers
			int cursorPos = Drawings.DrawAnswerButtons(currentPage.GetAnswers(), currentPage.GoBackPossible() && GoingBackAvailable());
			Console.WriteLine("");

			//Handle player input
			while (true)
			{
				Console.SetCursorPosition(Math.Max (0, cursorPos), Console.CursorTop);
				Console.Write("\\: ");

				//send input to server
				string input = Console.ReadLine().ToLower();
				NetworkManager.SendStringData (socket, input);

				//handle server response
				NetworkManager.NetCodes response = (NetworkManager.NetCodes) NetworkManager.ReceiveByteData(socket);

				if (response == NetworkManager.NetCodes.OK)
					return;
				else if (response == NetworkManager.NetCodes.INVALID_ANSWER)
					Drawings.DrawCenterTextLine("Sorry i didn't understand that!\n");
				else if (response == NetworkManager.NetCodes.BACK_NOT_POSSIBLE)
					Drawings.DrawCenterTextLine("You can't go back!\n");
				else if (response == NetworkManager.NetCodes.CONDITION_NOT_MET)
				{
					int indexAnswer = NetworkManager.ReceiveByteData (socket);
					string lockMessage = currentPage.GetAnswers().ElementAt (indexAnswer).GetLockMessage();

					if (lockMessage != null)
						lockMessage = "\n" + lockMessage + "\n";
					else
						lockMessage = "\nThe path is blocked...\n";

					Drawings.DrawCenterTextLine (lockMessage);
				}
			}
		}

		public override void Run()
		{
			while (true)
			{
				//Get current page from Server
				byte pageId = NetworkManager.ReceiveByteData (socket);

				//Exit game
				if (pageId == 255)
					break;
				else
				{
					SetCurrentPage (pageId);
					Frame();
				}
			}
			
			Console.WriteLine();
			Drawings.DrawCenterText("<<<< Good bye! Take care :) >>>>", 30);
			Console.ReadLine();
		}
	}
}
