using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace NetworkServer
{
	class Program
	{
		static void Main(string[] args)
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
			Socket client = listenerSocket.Accept();

			Console.WriteLine("Client connected. " + client.ToString()
				+ ", IPEndpoint: " + client.RemoteEndPoint.ToString());

			byte[] buffer = new byte [128];
			int numberOfReceivedBytes = 0;

			while (true)
			{
				//Waits for incoming data
				numberOfReceivedBytes = client.Receive (buffer);

				Console.WriteLine ("Number of received bytes: " + numberOfReceivedBytes);

				string message = Encoding.ASCII.GetString (buffer, 0, numberOfReceivedBytes);

				if (message == "KILL SERVER")
					break;

				Console.WriteLine ("Data sent by clients: " + message);

				//Sends data to client
				client.Send (buffer);

				//Clear buffer
				Array.Clear (buffer, 0, buffer.Length);
				numberOfReceivedBytes = 0;
			}
		}
	}
}
