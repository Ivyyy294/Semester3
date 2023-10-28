#include <IvyyyRectCollider.h>
#include "PrefabButton.h"

PrefabButton::PrefabButton ()
{
	transform.SetSpace (Transform2D::Space::SCREEN);
	transform.SetPivot (Transform2D::Pivot::TOPLEFT);

	fontMesh = AddComponent<FontMesh> ().get();
	fontMesh->SetSize (100.f, 24.f);
	fontMesh->text = L"Button";
	fontMesh->font.family = L"Consolas";
	fontMesh->font.height = 16;
	fontMesh->font.alignment = Font::HORIZONTAL_CENTER | Font::VERTICAL_CENTER;
	//fontMesh->drawGizmo = true;

	if (auto collider = AddComponent <RectCollider> ())
		collider->SetSize (fontMesh->GetWidth (), fontMesh->GetHeight ());

	script = AddComponent <AnswerButton> ().get();
}
