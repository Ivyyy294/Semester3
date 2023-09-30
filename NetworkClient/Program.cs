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
		static Socket ConnectToServer()
		{
			bool ok = false;
			//Create TCP Socket
			Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);;
			int port = 23000;

			while (!ok)
			{
				//Connect with local host
				string line = "[Enter server IPv4 address]\n";
				Drawings.DrawCenterText (line, 30);

				Console.SetCursorPosition(Math.Max (0, (Console.WindowWidth - line.Length) / 2), Console.CursorTop);
				Console.Write("\\: ");

				string strIpAddress = Console.ReadLine();
				IPAddress iPAddress = null;
				//Cast input to IPAddress
				try
				{
					iPAddress = IPAddress.Parse (strIpAddress);
				}
				catch (Exception excp)
				{
					Console.WriteLine();
					Drawings.DrawCenterText ("<<< [ERROR] >>>\n", 30, ConsoleColor.Red);
					Drawings.DrawCenterText ("<<< Invalid server address! >>>", 30, ConsoleColor.Red);
					Console.WriteLine("\n");
					continue;
				}

				//Connect to server
				try
				{
					Console.WriteLine();
					Drawings.DrawCenterText ("<<<< Connecting to server... >>>>\n", 30);
					server.Connect (iPAddress, port);

					Console.WriteLine();
					Drawings.DrawCenterText ("<<<< [Success] >>>>\n", 30, ConsoleColor.Green);

					Console.WriteLine();
					Drawings.DrawCenterText("[Press enter to continue...]", 30);
					Console.ReadLine();

					ok = true;
				}
				catch (Exception excp)
				{
					Console.WriteLine();					
					Drawings.DrawCenterText ("<<<< [ERROR] >>>>\n", 30, ConsoleColor.Red);
					Drawings.DrawCenterText ("<<<< Server not available! >>>>", 30, ConsoleColor.Red);
					Console.WriteLine("\n");
				}
			}

			return server;
		}

		static void Main(string[] args)
		{
			Console.OutputEncoding = Encoding.UTF8;

			Drawings.DrawLoadingScreen();

			Socket server = ConnectToServer();;

			try
			{
				GameSessionClient session = new GameSessionClient(server);
				session.Run();
			}
			catch (Exception excp)
            {
				Console.WriteLine();
                Console.WriteLine(excp.ToString());
				Console.ReadLine();
            }

			NetworkManager.CloseSocket (server);
		}
	}
}
