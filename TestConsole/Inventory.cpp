#include "Inventory.h"
#include "IvyyyEventSystem.h"

bool Inventory::GetMachineNotRepaired ()
{
	return !machineRepaired;
}

bool Inventory::GetMachineRepaired ()
{
	return machineRepaired;
}

bool Inventory::GetKey ()
{
	return key;
}

bool Inventory::GetLoose ()
{
	return !GetWin ();
}

bool Inventory::GetWin ()
{
	return water && food;
}

bool Inventory::GetRepairPossible ()
{
	return repairPossible && !machineRepaired;
}

void Inventory::Reset ()
{
	machineRepaired = { false };
	key = { false };
	water = { false };
	food = { false };
	repairPossible = { true };
}

Inventory::Inventory ()
{
	Ivyyy::EventSystem::Me ()->Event ("Key").Bind <Inventory, &Inventory::SetKey> (this);
	Ivyyy::EventSystem::Me ()->Event ("SetFood").Bind <Inventory, &Inventory::SetFood> (this);
	Ivyyy::EventSystem::Me ()->Event ("SetWater").Bind <Inventory, &Inventory::SetWater> (this);
	Ivyyy::EventSystem::Me ()->Event ("SetMachineRepaired").Bind <Inventory, &Inventory::SetMachineRepaired> (this);
	Ivyyy::EventSystem::Me ()->Event ("SetMachineDestroyed").Bind <Inventory, &Inventory::SetMachineDestroyed> (this);
}
