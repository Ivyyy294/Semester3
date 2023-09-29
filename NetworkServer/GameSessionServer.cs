using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using EscapeFromMedinaStation;
using System.Net.Sockets;

namespace NetworkServer
{
	public class GameSessionServer : GameSession
	{
		public GameSessionServer (Socket _socket)
			: base (_socket)
		{
		}

		public override void Frame ()
		{
			Page currentPage = GetCurrentPage();

			currentPage.Action();

			NetworkManager.SendByteData (socket, currentPage.GetPageId());

			//Get input
			while (true)
			{
				string input = NetworkManager.ReceiveStringData (socket);

				if (input.Contains("back"))
				{
					if (GoingBackAvailable())
					{
						GoBack();
						NetworkManager.SendByteData (socket, NetworkManager.NetCodes.OK);
						return;
					}

					NetworkManager.SendByteData (socket, NetworkManager.NetCodes.BACK_NOT_POSSIBLE); //You can't go back!
				}
				else
				{
					bool validInput = false;
					Stack <Answer> answers = currentPage.GetAnswers();

					for (int i = 0; i < answers.Count(); ++i)
					{
						Answer answer = answers.ElementAt (i);

						if (answer.IsVisible() && input.Contains(answer.GetKeyword()))
						{
							validInput = true;

							if (answer.CheckCondition())
							{
								SetCurrentPage(answer.GetPageNr());
								NetworkManager.SendByteData (socket, NetworkManager.NetCodes.OK); //OK
								return;
							}
							else
							{
								NetworkManager.SendByteData (socket, NetworkManager.NetCodes.CONDITION_NOT_MET);
								NetworkManager.SendByteData (socket, (byte) i);
							}
						}
					}

					if (!validInput)
						NetworkManager.SendByteData (socket, NetworkManager.NetCodes.INVALID_ANSWER); //Sorry i didn't understand that!
				}
			}
		}

		public override void Run ()
		{
			Thread ctThread = new Thread(RunIntern);
			ctThread.Start();
		}

		void RunIntern()
		{
			try
			{
				while (true)
				{
					byte pageId = GetCurrentPageId();

					if (pageId == 255)
					{
						//send exit code to client
						NetworkManager.SendByteData (socket, pageId);
						break;
					}

					Frame();
				}

				Console.WriteLine("Client disconnected. " + socket.ToString()
					+ ", IPEndpoint: " + socket.RemoteEndPoint.ToString());
			}
			catch (Exception excp)
            {
				Console.WriteLine(excp.ToString());
            }
			
			NetworkManager.CloseSocket (socket);
		}
	}
}
