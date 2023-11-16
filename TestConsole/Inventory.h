#pragma once
class Inventory
{
public:
	static Inventory& Me ()
	{
		static Inventory me;
		return me;
	}

	bool GetMachineNotRepaired ();
	bool GetMachineRepaired ();
	bool GetKey ();
	bool GetLoose ();
	bool GetWin ();
	bool GetRepairPossible ();

	void Reset ();
private:
	inline void SetKey () { key = true; };
	inline void SetFood () { food = true; };
	inline void SetWater () { water = true; };
	inline void SetMachineRepaired () { machineRepaired = true; };
	inline void SetMachineDestroyed () { repairPossible = false; };

	Inventory ();

	bool machineRepaired{ false };
	bool key{ false };
	bool water{ false };
	bool food{ false };
	bool repairPossible{ true };
};

