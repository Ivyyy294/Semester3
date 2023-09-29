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

			currentPage.Draw();

			int cursorPos = Drawings.DrawAnswerButtons(currentPage.GetAnswers(), currentPage.GoBackPossible() && GoingBackAvailable());
			Console.WriteLine("");

			while (true)
			{
				Console.SetCursorPosition(Math.Max (0, cursorPos), Console.CursorTop);
				Console.Write("\\: ");

				string input = Console.ReadLine().ToLower();
				NetworkManager.SendStringData (socket, input);

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
				byte pageId = NetworkManager.ReceiveByteData (socket);

				if (pageId == 255)
					break;
				else
				{
					SetCurrentPage (pageId);
					Frame();
				}
			}
			
			Drawings.DrawCenterTextLine("Good bye! Take care :)");
			Console.ReadLine();
		}
	}
}
