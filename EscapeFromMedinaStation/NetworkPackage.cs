using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.Net.Sockets;

namespace EscapeFromMedinaStation
{
	public class NetworkPackage
	{
		private int maxSize = 2048;
		private Socket socket;
		private Dictionary <string, NetworkPackageValue> valueMap = new Dictionary<string, NetworkPackageValue>();

		//Public Values
		public NetworkPackage (Socket _socket) { socket = _socket;}

		//Adds a new NetworkPackageValue to the content list
		public void AddValue (string name, NetworkPackageValue val) {valueMap[name] = val;}
		public void AddValue (string name, NetworkPackageValue.Type type) {valueMap[name] = new NetworkPackageValue (type);}

		//Returns the cached NetworkPackageValue to the given key
		//Return null if content list does not contains key
		public NetworkPackageValue Value (string name)
		{
			NetworkPackageValue val = null;

			if (valueMap.ContainsKey (name))
				val = valueMap[name];

			return val;
		}

		//Returns the sum of the size of the contents in bytes
		public int Size()
		{
			int size = 0;

			foreach (var i in valueMap)
				size += i.Value.Size();

			return size;
		}

		//Sends the serilized content via the socket 
		public void Send ()
		{
			socket.Send (GetBytes());
		}

		//Try to read package data from socket
		public bool Receive ()
		{
			byte[] buffer = new byte[maxSize];
			socket.Receive (buffer);
			return ReadBytes (buffer);
		}

		public byte[] GetBytes()
		{
			//Init byte array with package size
			byte[] value = new byte[Size()];

			int index = 0;

			foreach (var i in valueMap)
			{
				int size = i.Value.Size();

				//copy content bytes to the correct position in value byte array
				Buffer.BlockCopy (i.Value.GetBytes(), 0, value, index, size);

				//Adding current size to index offset to get the memmory position for the next entry 
				index += size;
			}

			return value;
		}

		//Private Functions
		private bool ReadBytes (byte[] bytes)
		{
			try
			{
				int index = 0;

				foreach (var i in valueMap)
				{
					int size = i.Value.Size();

					//Read string length vom bytes
					if (i.Value.GetTypInfo() == NetworkPackageValue.Type.STRING)
						size = sizeof (int) + BitConverter.ToInt32 (bytes, index);

					byte[] buffer = new byte[size];
					Buffer.BlockCopy (bytes, index, buffer, 0, size);
					i.Value.SetBytes (buffer);

					//Adding current size to index offset to get the memmory position for the next entry 
					index += size;
				}

				return true;
			}
			catch (Exception excp)
			{
				return false;
			}
		}
	}
}
