#pragma once
#include <IvyyyGameObject.h>
#include "ButtonController.h"
#include "PrefabButton.h"

using namespace Ivyyy;

class PrefabButtonController
	: public GameObject
{
public:
	PrefabButtonController ();
	void AddButton (PrefabButton* button);

private:
	ButtonController* buttonController;
};

