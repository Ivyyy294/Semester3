#include "PrefabLogo.h"
#include "IvyyyScreen.h"
#include "Drawings.h"

PrefabLogo::PrefabLogo ()
	: PrefabDrawing()
{
	float width = 420.f;
	float height = 420.f;
	transform.GetLocalPosition ().x = (Screen::CurrentResolution().width - width) * 0.5f;
	fontMesh->SetSize (width, height);
	fontMesh->font.height = 14;
}
