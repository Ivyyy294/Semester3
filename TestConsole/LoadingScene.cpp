#include "LoadingScene.h"
#include "PrefabLogo.h"
#include "Drawings.h"
#include "LoadingText.h"
#include "IvyyyScreen.h"

void LoadingScene::Init ()
{
	auto img = AddGameObject <PrefabLogo>();
	img->SetDrawing (Drawings::LoadingScreen ());
	img->transform.GetLocalPosition ().x += 14.f;

	auto text = AddGameObject <GameObject> ();
	text->AddComponent <FontMesh> ();
	text->AddComponent <LoadingText> ();
	text->transform.GetLocalPosition ().y = 500;
	text->transform.GetLocalPosition ().x = Screen::CurrentResolution ().width * 0.5f;
}
