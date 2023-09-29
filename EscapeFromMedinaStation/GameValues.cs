using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
	public class GameValues
	{
		private bool key = false;
		private bool food = false;
		private bool water = false;
		private bool repairPossible = true;
		private bool machineRepaired = false;

		public void SetKey() {key = true;}
		public void SetFood() { food = true; }
		public void SetRepairPosible() { repairPossible = false; }
		public void SetWater() { water = true; }
		public void SetMachineRepaired() { machineRepaired = true; }
		public bool CheckKey() {return key;}
		public bool GetLoose() { return !GetWin(); }
		public bool GetWin() { return water && food; }
		public bool GetRepairPossible() { return repairPossible && !machineRepaired; }
		public bool GetMachineRepaired() { return machineRepaired; }
		public bool GetMachineNotRepaired() { return !machineRepaired; }

		public void ResetGameValues()
		{
			machineRepaired = false;
			repairPossible = true;
			water = false;
			key = false;
			food = false;
		}
	}

}
