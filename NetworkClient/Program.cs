using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using EscapeFromMedinaStation;

namespace NetworkClient
{
	class Program
	{
		static void Main(string[] args)
		{
			Page.InitContent();
			Console.OutputEncoding = Encoding.UTF8;

			//Create TCP Socket
			Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			
			//Connect with local host
			IPAddress iPAddress = IPAddress.Parse ("127.0.0.1");
			int port = 23000;

			Console.WriteLine("Connecting to server...");
			server.Connect (iPAddress, port);

			Drawings.DrawLoadingScreen();
			
			while (true)
			{
				byte pageId = NetworkManager.ReceiveByteData (server);

				if (pageId == 255)
					break;
				else
				{
					Page current = Page.GetPage (pageId);
					current?.RunClient (server);
				}
			}
			
			Drawings.DrawCenterTextLine("Good bye! Take care :)");
			Console.ReadLine();

			//while (true)
			//{
			//	//Get input from console
			//	string inputCommand = Console.ReadLine();

			//	//cast input to byte array
			//	byte[] buffer = Encoding.ASCII.GetBytes (inputCommand);

			//	//send data to server
			//	server.Send (buffer);

			//	if (inputCommand == "KILL SERVER")
			//		break;

			//	byte[] inputBuffer = new byte [128];

			//	//Get data from server
			//	int numberOfReceivedBytes = server.Receive (inputBuffer);
			//	string dataReceived = Encoding.ASCII.GetString (inputBuffer, 0, numberOfReceivedBytes);
			//	Console.WriteLine ("Answer: " + dataReceived);
			//}
		}
	}
}
