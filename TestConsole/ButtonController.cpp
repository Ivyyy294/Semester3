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

	float xPos = -totalWidth * 0.5f;

	for (const auto& i : buttonVec)
	{
		if (i->IsActive ())
		{
			Vector2 localPos = i->transform.GetLocalPosition();
			localPos.x = xPos;
			i->transform.SetLocalPosition (localPos);
			xPos += i->GetWidth ();
		}
	}
}

void ButtonController::ActivateButton (const int index, const std::wstring& label)
{
	if (index < buttonVec.size ())
	{
		buttonVec[index]->SetText (label);
		buttonVec[index]->SetActive (true);
	}
}

void ButtonController::DisableButton (const int index)
{
	buttonVec[index]->SetActive (false);
}
