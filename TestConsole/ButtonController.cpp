#include "ButtonController.h"

ButtonController::ButtonController ()
{
}

void ButtonController::AddButton (PrefabButton* button)
{
	button->SetParent (gameObject);
	buttonVec.push_back (button);
}

void ButtonController::Update ()
{
	float totalWidth = 0.f;
	float xStart = -totalWidth * 0.5;

	for (const auto& i : buttonVec)
		totalWidth += i->GetWidth ();


}
