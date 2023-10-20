using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
	interface BaseStorage
	{
		bool InsertEntry (int index, string value);
		void PushEntry (string value);
		string GetEntry (int index);
		bool RemoveEntry (int index);
		string[] GetSortedList();
	}

	public class MapStorage : BaseStorage
	{
		public bool InsertEntry (int index, string value)
		{
			data[index] = value;

			if (index > max)
				max = index;

			return true;
		}

		public void PushEntry (string value)
		{
			data[max++] = value;
		}

		public string GetEntry (int index)
		{
			if (data.ContainsKey(index))
				return data[index];
			
			return null;
		}

		public bool RemoveEntry (int index)
		{
			if (data.ContainsKey (index))
			{
				data.Remove (index);
				return true;
			}

			return false;
		}

		public string[] GetSortedList()
		{
			string[] list = new string [data.Count];
			for (int i = 0; i < data.Count; ++i)
				list[i] = data[i];

			Array.Sort (list);
			return list;
		}

		private Dictionary <int, string> data = new Dictionary<int, string>();
		private int max;
	}

	public class ListStorage : BaseStorage
	{
		public bool InsertEntry (int index, string value)
		{
			data.Insert (index, value);
			return true;
		}

		public void PushEntry (string value)
		{
			data.Add (value);
		}

		public string GetEntry (int index)
		{
			return data[index];
		}

		public bool RemoveEntry (int index)
		{
			if (index < data.Count)
			{
				data.RemoveAt (index);
				return true;
			}

			return false;
		}

		public string[] GetSortedList()
		{
			string[] list = data.ToArray();
			Array.Sort (list);
			return list;
		}

		List <string> data = new List<string>();
	}

	public class ArrayStorage : BaseStorage
	{
		public ArrayStorage()
		{
			size = 2;
			data = new string[size];
			index = 0;
		}

		public bool InsertEntry (int _index, string value)
		{
			if (_index < size)
			{
				//Save Range
				int range = size - _index;
				string[] dataToMove = new string[range];
				Array.Copy (data, _index, dataToMove, 0, range);

				//Resize in case there is no space for one more entry
				if (index + 1 >= size)
					Resize();

				data[_index] = value;

				Array.Copy (dataToMove, 0, data, _index + 1, range);
				index++;

				return true;
			}

			return false;
		}

		public void PushEntry (string value)
		{
			if (index >= size)
				Resize();

			data[index++] = value;
		}

		public string GetEntry (int index)
		{
			if (index < size)
				return data[index];
			else 
				return null;
		}

		public bool RemoveEntry (int _index)
		{
			if (_index < size)
			{
				//Save Range
				int range = size - _index - 1;
				string[] dataToMove = new string[range];
				Array.Copy (data, _index + 1, dataToMove, 0, range);
				Array.Copy (dataToMove, 0, data, _index, range);
			}

			return false;
		}

		public string[] GetSortedList()
		{
			string[] list = new string[index -1];
			Array.Copy (data, list, index-1);
			Array.Sort (list);
			return list;
		}

		private void Resize()
		{
			int newSize = size * 2;
			string[] newData = new string[newSize];
			Array.Copy (data, newData, size);
			data = newData;
			size = newSize;
		}

		private string[] data;
		int index;
		int size;
	}
}
