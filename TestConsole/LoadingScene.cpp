#include "LoadingScene.h"
#include "PrefabLogo.h"
#include "Drawings.h"
#include "LoadingText.h"
#include "IvyyyScreen.h"

void LoadingScene::Init ()
{
	float xCenter = Screen::CurrentResolution().width * 0.5f;

	auto img = AddGameObject <PrefabLogo>();
	img->SetDrawing (Drawings::LoadingScreen ());
	Vector2 newPos = img->transform.GetLocalPosition();
	newPos.x += 14.f;
	img->transform.SetLocalPosition (newPos);

	auto text = AddGameObject <GameObject> ();
	text->AddComponent <FontMesh> ();
	text->AddComponent <LoadingText> ();
	text->transform.SetLocalPosition (Vector2(xCenter, 500.f));
}
