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
	drawing->transform.GetLocalPosition ().y = 100.f;
	pageController->prefabDrawing = drawing.get ();

	//Add Page Text
	auto pageTextObj = AddGameObject<GameObject> ();
	pageTextObj->transform.SetSpace (Transform2D::Space::SCREEN);
	float width = 800.f;
	pageTextObj->transform.SetPosition (Vector2 (xCenter -width * 0.5f, 315.f));

	auto textMesh = pageTextObj->AddComponent <FontMesh> ();
	textMesh->Transform ()->SetPivot (Transform2D::Pivot::TOPLEFT);
	textMesh->SetSize (800.f, 200.f);
	textMesh->font.family = L"Consolas";
	textMesh->font.height = 16;
	textMesh->font.alignment = Font::VERTICAL_CENTER | Font::HORIZONTAL_TOP;
	pageController->textMesh = textMesh.get();

	//Add PrefabButtonController
	auto buttonController = AddGameObject <PrefabButtonController> ();
	buttonController->transform.GetLocalPosition ().x = xCenter;
	buttonController->transform.GetLocalPosition ().y = 400.f;
	pageController->buttonController = buttonController->GetComponent <ButtonController>().get();

	auto backButton = AddGameObject <PrefabButton> ();
	backButton->SetText (L"[ back ]");
	backButton->SetEvent ("Back");
	buttonController->AddButton (backButton.get ());

	for (int i = 0; i <= 6; ++i)
	{
		auto button = AddGameObject <PrefabButton> ();
		button->SetText (L"[ Button ]");
		button->SetEvent ("Answer" + std::to_string(i+1));
		buttonController->AddButton (button.get());
	}
}
