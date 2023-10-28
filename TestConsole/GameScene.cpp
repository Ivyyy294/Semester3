#include <IvyyyScreen.h>
#include "GameScene.h"
#include "PrefabDrawing.h"
#include "PrefabButton.h"
#include "PrefabButtonController.h"
#include "Drawings.h"
#include "Player.h"

void GameScene::Init ()
{
	float xCenter = Screen::CurrentResolution ().width * 0.5f;
	auto drawing = AddGameObject <PrefabDrawing> ();
	drawing->SetDrawing (Drawings::Menu());
	drawing->transform.GetLocalPosition ().y = 100.f;

	auto buttonController = AddGameObject <PrefabButtonController> ();
	buttonController->transform.GetLocalPosition ().x = xCenter;
	buttonController->transform.GetLocalPosition ().y = 500;

	auto button1 = AddGameObject <PrefabButton> ();
	button1->SetText (L"[ Button1 ]");

	buttonController->AddButton (button1.get());

	AddGameObject <Player> ();
}