using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
public class NetworkPackageValue
	{
		public enum Type
		{
			SHORT,
			USHORT,
			INT,
			UINT,
			FLOAT,
			CHAR,
			BOOL,
			STRING
		}

		byte[] value;
		Type type;

		public int Size () {return (value != null ? value.Length : 0);}
		public byte[] GetBytes() { return value;}
		public void SetBytes (byte[] bytes) { value = bytes;}
		public NetworkPackageValue (short val) {SetValue (val);}
		public NetworkPackageValue (ushort val) {SetValue (val);}
		public NetworkPackageValue (int val) {SetValue (val);}
		public NetworkPackageValue (uint val) {SetValue (val);}
		public NetworkPackageValue (float val) {SetValue (val);}
		public NetworkPackageValue (char val) {SetValue (val);}
		public NetworkPackageValue (bool val) {SetValue (val);}
		public NetworkPackageValue (string val) {SetValue (val);}
		
		//Reserves requiered memory
		public NetworkPackageValue (Type _type)
		{
			type = _type;

			if (type == Type.SHORT) value = new byte[sizeof (short)];
			else if (type == Type.USHORT) value = new byte[sizeof (ushort)];
			else if (type == Type.INT) value = new byte[sizeof (int)];
			else if (type == Type.UINT) value = new byte[sizeof (uint)];
			else if (type == Type.FLOAT) value = new byte[sizeof (float)];
			else if (type == Type.CHAR) value = new byte[sizeof (char)];
			else if (type == Type.BOOL) value = new byte[sizeof (bool)];
			else if (type == Type.STRING) value = new byte[4]; //Size will be dynamicly determined
		}

		public void SetValue (short val) {value = BitConverter.GetBytes (val); type = Type.SHORT;}
		public void SetValue (ushort val) {value = BitConverter.GetBytes (val); type = Type.USHORT;}
		public void SetValue (int val) {value = BitConverter.GetBytes (val); type = Type.INT;}
		public void SetValue (uint val) {value = BitConverter.GetBytes (val); type = Type.UINT;}
		public void SetValue (float val) {value = BitConverter.GetBytes (val); type = Type.FLOAT;}
		public void SetValue (char val) {value = BitConverter.GetBytes (val); type = Type.CHAR;}
		public void SetValue (bool val) {value = BitConverter.GetBytes (val); type = Type.BOOL;}
		public void SetValue (string val)
		{
			int offset = sizeof (int);
			value = new byte[offset + val.Length];;
			byte[] buffer = new byte[val.Length];
			buffer = Encoding.ASCII.GetBytes (val);
			Buffer.BlockCopy (BitConverter.GetBytes(val.Length), 0, value, 0, offset);
			Buffer.BlockCopy (buffer, 0, value, offset, val.Length);
			type = Type.STRING;
		}

		public Type GetTypInfo () { return type;}
		public short GetShort() {return BitConverter.ToInt16 (value, 0);}
		public ushort GetUShort() {return BitConverter.ToUInt16 (value, 0);}
		public int GetInt32() {return BitConverter.ToInt32 (value, 0);}
		public uint GetUInt32() {return BitConverter.ToUInt32 (value, 0);}
		public float GetFloat() {return BitConverter.ToSingle (value, 0);}
		public char GetChar() {return BitConverter.ToChar (value, 0);}
		public bool GetBool() {return BitConverter.ToBoolean (value, 0);}
		public string GetString() {return Encoding.ASCII.GetString (value, sizeof (int), Size() - sizeof (int));}
	}
}
