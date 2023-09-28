using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
	public class GameValues
	{
		static private byte currentPage = 254;
		static public Stack<byte> pageHistorie = new Stack<byte>();
		static private bool key = false;
		static private bool food = false;
		static private bool water = false;
		static private bool repairPossible = true;
		static private bool machineRepaired = false;

		static public void SetCurrentPage(byte newPage)
		{
			if (Page.GetCurrentPage().GetHistorie())
				pageHistorie.Push(currentPage);
			currentPage = newPage;
		}

		static public byte GetCurrentPage()
		{
			return currentPage;
		}

		static public void GoBack()
		{
			if (pageHistorie.Count > 0)
				currentPage = pageHistorie.Pop();
			else
				currentPage = 0;
		}

		static public bool GoingBackAvailable()
		{
			if (pageHistorie.Count == 0)
				return false;
			else
			{
				return pageHistorie.Peek() != 254;
			}
		}

		static public void SetKey() {key = true;}
		static public void SetFood() { food = true; }
		static public void SetRepairPosible() { repairPossible = false; }
		static public void SetWater() { water = true; }
		static public void SetMachineRepaired() { machineRepaired = true; }
		static public bool CheckKey() {return key;}
		static public bool GetLoose() { return !GetWin(); }
		static public bool GetWin() { return water && food; }
		static public bool GetRepairPossible() { return repairPossible && !machineRepaired; }
		static public bool GetMachineRepaired() { return machineRepaired; }
		static public bool GetMachineNotRepaired() { return !machineRepaired; }
		static public void ResetGameValues()
		{
			machineRepaired = false;
			repairPossible = true;
			water = false;
			key = false;
			food = false;
			pageHistorie.Clear();
			currentPage = 254;
		}
	}

}
