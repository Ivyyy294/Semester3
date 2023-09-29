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
			Console.OutputEncoding = Encoding.UTF8;

			//Create TCP Socket
			Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			
			//Connect with local host
			IPAddress iPAddress = IPAddress.Parse ("127.0.0.1");
			int port = 23000;

			Console.WriteLine("Connecting to server...");
			server.Connect (iPAddress, port);

			GameSessionClient session = new GameSessionClient(server);

			session.Run();
		}
	}
}
