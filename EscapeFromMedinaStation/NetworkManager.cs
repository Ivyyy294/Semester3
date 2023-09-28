using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;

namespace EscapeFromMedinaStation
{
	public class NetworkManager
	{
		static public byte ReceiveByteData (Socket socket)
		{
			byte[] inputBuffer = new byte [128];
			socket.Receive (inputBuffer);
			return inputBuffer[0];
		}

		static public string ReceiveStringData(Socket socket)
		{
			byte[] inputBuffer = new byte [128];
			int numberOfReceivedBytes = socket.Receive (inputBuffer);
			return Encoding.ASCII.GetString (inputBuffer, 0, numberOfReceivedBytes);
		}

		static public void SendStringData (Socket socket, string data)
		{
			byte[] buffer = Encoding.ASCII.GetBytes (data);
			socket.Send (buffer);
		}

		static public void SendByteData (Socket socket, byte data)
		{
			byte[] buffer = BitConverter.GetBytes (data);
			socket.Send (buffer);
		}
	}
}
