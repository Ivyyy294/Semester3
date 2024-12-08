#include "JonasScene.h"
#include "Player.h"
#include "PrefabCoin.h"
#include "PrefabScore.h"
#include "Score.h"
#include "Coin.h"
#include "DebugInfo.h"

void JonasScene::Init ()
{
	auto player = AddGameObject <Player> ();
	auto test1 = AddGameObject <PrefabCoin> ();
	test1->transform.SetLocalPosition (Vector2(128.f, 0.f));
	test1->SetParent (player.get());
	auto test2 = AddGameObject <PrefabCoin> ();
	test2->transform.SetLocalPosition(Vector2(128.f, 0.f));
	test2->SetParent (test1.get ());

	/*std::vector<Vector2> posVec;
	posVec.push_back (Vector2 (-128.f, 128.f));
	posVec.push_back (Vector2 (128.f, 128.f));
	posVec.push_back (Vector2 (-128.f, -128.f));
	posVec.push_back (Vector2 (128.f, -128.f));

	auto scoreObj = AddGameObject <PrefabScore> ();
	auto score = scoreObj->GetComponent<Score> ();

	for (int i = 0; i < posVec.size() * 200; ++i)
	{
		int index = i % posVec.size ();
		const auto& pos = posVec[index];
		auto coin = AddGameObject <PrefabCoin> ();
		coin->transform.SetPosition (pos);
	}*/

	//Add Debug Object
	auto debug = AddGameObject <GameObject> ();
	debug->transform.SetSpace (Transform2D::Space::SCREEN);
	debug->transform.SetPivot (Transform2D::Pivot::TOPLEFT);
	debug->transform.SetLocalPosition (Vector2 (0, 64));
	auto fontMesh = debug->AddComponent<FontMesh> ();
	fontMesh->font.color = Color (255, 0, 0);
	fontMesh->font.height = 12;
	fontMesh->SetSize (200.f, 32.f);
	debug->AddComponent<DebugInfo> ();
}
