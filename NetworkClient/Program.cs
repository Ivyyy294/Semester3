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
			//Create TCP Socket
			Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			
			//Connect with local host
			IPAddress iPAddress = IPAddress.Parse ("127.0.0.1");
			int port = 23000;

			Console.WriteLine("Connecting to server...");
			server.Connect (iPAddress, port);
			Console.WriteLine("Succesful");


			while (true)
			{
				//Get input from console
				string inputCommand = Console.ReadLine();

				//cast input to byte array
				byte[] buffer = Encoding.ASCII.GetBytes (inputCommand);

				//send data to server
				server.Send (buffer);

				if (inputCommand == "KILL SERVER")
					break;

				byte[] inputBuffer = new byte [128];

				//Get data from server
				int numberOfReceivedBytes = server.Receive (inputBuffer);
				string dataReceived = Encoding.ASCII.GetString (inputBuffer, 0, numberOfReceivedBytes);
				Console.WriteLine ("Answer: " + dataReceived);
			}
		}
	}
}
