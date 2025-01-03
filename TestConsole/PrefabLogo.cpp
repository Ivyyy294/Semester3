#include "PrefabLogo.h"
#include "IvyyyScreen.h"
#include "Drawings.h"

PrefabLogo::PrefabLogo ()
	: PrefabDrawing()
{
	float width = 420.f;
	float height = 420.f;
	transform.SetLocalPosition (Vector3((Screen::CurrentResolution().width - width) * 0.5f, 0.f, 0.f));
	fontMesh->SetSize (width, height);
	fontMesh->font.height = 14;
}
