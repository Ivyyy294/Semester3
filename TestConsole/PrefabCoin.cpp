#include "PrefabCoin.h"
#include <IvyyyFontMesh.h>
#include <IvyyyRectCollider.h>
#include "Coin.h"

PrefabCoin::PrefabCoin ()
{
	FontMesh* fontMesh = AddComponent<FontMesh> ().get ();
	fontMesh->SetSize (100.f, 24.f);
	fontMesh->text = L"Coin";
	fontMesh->font.family = L"Consolas";
	fontMesh->font.height = 16;
	fontMesh->font.alignment = Font::HORIZONTAL_CENTER | Font::VERTICAL_CENTER;
	fontMesh->drawGizmo = true;

	if (auto collider = AddComponent <RectCollider> ())
	{
		collider->SetSize (fontMesh->GetWidth (), fontMesh->GetHeight ());
		collider->SetTrigger (true);
	}

	AddComponent <Coin> ();
}
