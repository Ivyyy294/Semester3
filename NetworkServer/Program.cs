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
			Socket listenerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			IPAddress iPAddress = IPAddress.Any;
			IPEndPoint iPEndPoint = new IPEndPoint (iPAddress, 23000);
			listenerSocket.Bind (iPEndPoint);

			listenerSocket.Listen (5);

			Console.WriteLine("Waiting for clients...");

			Socket client = listenerSocket.Accept();

			Console.WriteLine("Client connected. " + client.ToString()
				+ ", IPEndpoint: " + client.RemoteEndPoint.ToString());

			byte[] buffer = new byte [128];
			int numberOfReceivedBytes = 0;

			while (true)
			{
				numberOfReceivedBytes = client.Receive (buffer);

				Console.WriteLine ("Number of received bytes: " + numberOfReceivedBytes);

				string message = Encoding.ASCII.GetString (buffer, 0, numberOfReceivedBytes);

				if (message == "KILL SERVER")
					break;

				Console.WriteLine ("Data sent by clients: " + message);

				client.Send (buffer);

				Array.Clear (buffer, 0, buffer.Length);
				numberOfReceivedBytes = 0;
			}
		}
	}
}
