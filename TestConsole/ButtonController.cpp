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

	for (const auto& i : buttonVec)
	{
		if (i->IsActive())
			totalWidth += i->GetWidth ();
	}

	float xPos = -totalWidth * 0.5;

	for (const auto& i : buttonVec)
	{
		if (i->IsActive ())
		{
			i->transform.GetLocalPosition ().x = xPos;
			xPos += i->GetWidth ();
		}
	}

}
