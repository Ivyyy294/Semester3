using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace NetworkClient
{
	class Program
	{
		static void Main(string[] args)
		{
			Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			IPAddress iPAddress = IPAddress.Parse ("127.0.0.1");
			int port = 23000;

			Console.WriteLine("Connecting to server...");
			server.Connect (iPAddress, port);
			Console.WriteLine("Succesful");

			while (true)
			{
				string inputCommand = Console.ReadLine();

				byte[] buffer = Encoding.ASCII.GetBytes (inputCommand);
				server.Send (buffer);
			}
		}
	}
}
