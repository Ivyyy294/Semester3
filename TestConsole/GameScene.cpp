#include <IvyyyScreen.h>
#include "GameScene.h"
#include "PrefabDrawing.h"
#include "PrefabButton.h"
#include "PrefabButtonController.h"
#include "Drawings.h"
#include "PageController.h"

void GameScene::Init ()
{
	//Add Page Controller
	auto pageController = AddGameObject <GameObject> ()->AddComponent<PageController>();

	//Add PrefabDrawing
	float xCenter = Screen::CurrentResolution ().width * 0.5f;
	auto drawing = AddGameObject <PrefabDrawing> ();
	drawing->SetDrawing (Drawings::Menu());
	drawing->transform.GetLocalPosition ().y = 100.f;
	pageController->prefabDrawing = drawing.get ();

	//Add PrefabButtonController
	auto buttonController = AddGameObject <PrefabButtonController> ();
	buttonController->transform.GetLocalPosition ().x = xCenter;
	buttonController->transform.GetLocalPosition ().y = 300;
	pageController->buttonController = buttonController->GetComponent <ButtonController>().get();

	for (int i = 0; i < 4; ++i)
	{
		auto button = AddGameObject <PrefabButton> ();
		button->SetText (L"[ Button ]");
		button->SetEvent ("Answer" + std::to_string(i+1));
		buttonController->AddButton (button.get());
	}
}
