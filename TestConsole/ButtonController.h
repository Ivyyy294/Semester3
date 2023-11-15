#pragma once
#include <IvyyyComponent.h>
#include <vector>
#include "PrefabButton.h"

using namespace Ivyyy;

class ButtonController
	: public Component
{
public:
	ButtonController ();
	void AddButton (PrefabButton* button);
	void Update () override;

	void ActivateButton (const int index, const std::wstring& label);
	void DisableButton (const int index);

	PrefabButton* GetButton (int index);
private:
	std::vector <PrefabButton*> buttonVec;
};

