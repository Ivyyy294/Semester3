#pragma once
class Inventory
{
public:
	inline static Inventory& Me () { return me; };

	inline bool GetMachineNotRepaired () { return !machineRepaired; };
	inline bool GetMachineRepaired () { return machineRepaired; };
	inline bool GetKey () { return key; };
	inline bool GetLoose () { return !GetWin (); }
	inline bool GetWin () { return water && food; }
	inline bool GetRepairPossible () { return repairPossible && !machineRepaired; }
private:
	static Inventory me;
	bool machineRepaired{ false };
	bool key{ false };
	bool water{ false };
	bool food{ false };
	bool repairPossible{ true };
};

