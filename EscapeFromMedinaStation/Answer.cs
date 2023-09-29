using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
	public class Answer
	{
		private string keyword;
		private byte pageNr;
		private string lockMessage = null;
		Func<bool> lockCondition = null;
		Func<bool> visibleCondition = null;

		public Answer(string key, byte p)
		{
			keyword = key;
			pageNr = p;
		}

		public string GetLockMessage()
		{
			return lockMessage;
		}

		public void SetLockCondition(Func<bool> c, string msg)
		{
			lockCondition = c;
			lockMessage = msg;
		}

		public void SetVisibleCondition(Func<bool> c) { visibleCondition = c; }

		public bool IsVisible ()
		{
			if (visibleCondition != null)
				return visibleCondition();
			else
				return true;
		}

		public bool CheckCondition ()
		{
			if (lockCondition == null)
				return true;
			else
			{
				if (lockCondition())
					return true;
				else
					return false;
			}
		}
		public string GetKeyword() { return keyword; }
		public byte GetPageNr() { return pageNr; }
	}
}
