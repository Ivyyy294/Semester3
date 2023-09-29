using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using EscapeFromMedinaStation;

namespace NetworkServer
{
	class Program
	{
		static Socket GetClientSocket()
		{
			//Create TCP Socket
			Socket listenerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			
			//Accepts connection fromm any IP address
			IPAddress iPAddress = IPAddress.Any;

			//Listens to port 23000
			IPEndPoint iPEndPoint = new IPEndPoint (iPAddress, 23000);
			listenerSocket.Bind (iPEndPoint);

			//Allows up to 5 incomming connections
			listenerSocket.Listen (5);

			Console.WriteLine("Waiting for clients...");

			//Waits for a client to connect
			return listenerSocket.Accept();
		}

		static void Main(string[] args)
		{
			GameSession session = new GameSession();
			session.InitContent();
			Socket client = GetClientSocket();

			Console.WriteLine("Client connected. " + client.ToString()
				+ ", IPEndpoint: " + client.RemoteEndPoint.ToString());

			while (true)
			{
				byte pageId = session.GetCurrentPageId();

				Console.WriteLine ("Current Page: " + pageId);

				if (pageId == 255)
					break;

				session.RunServer(client);
			}
		}
	}
}
