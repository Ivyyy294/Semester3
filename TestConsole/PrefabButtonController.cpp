#include "PrefabButtonController.h"

PrefabButtonController::PrefabButtonController ()
{
	transform.SetSpace (Transform2D::Space::SCREEN);
	buttonController = AddComponent <ButtonController> ().get();
}

void PrefabButtonController::AddButton (PrefabButton* button)
{
	buttonController->AddButton (button);
}
