#include "PrefabDrawing.h"
#include "IvyyyScreen.h"
#include "Drawings.h"

PrefabDrawing::PrefabDrawing ()
{
	float width = 440.f;
	float height = 200.f;
	transform.SetSpace (Transform2D::Space::SCREEN);
	transform.SetPivot (Transform2D::Pivot::TOPLEFT);
	transform.GetLocalPosition ().x = (Screen::CurrentResolution ().width - width) * 0.5f;
	fontMesh = AddComponent<FontMesh> ().get();
	fontMesh->SetSize (width, height);
	fontMesh->text = L"Placeholder";
	fontMesh->font.family = L"Consolas";
	fontMesh->font.height = 16;
	fontMesh->font.color = Color (255, 255, 255);
	fontMesh->font.alignment = Font::VERTICAL_LEFT | Font::HORIZONTAL_TOP;
	//fontMesh->drawGizmo = true;
}

void PrefabDrawing::SetDrawing (const std::wstring& drawing)
{
	fontMesh->text = drawing;
}
