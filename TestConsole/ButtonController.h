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

private:
	std::vector <PrefabButton*> buttonVec;
};

