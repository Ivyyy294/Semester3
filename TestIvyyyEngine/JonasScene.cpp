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
	auto test1 = AddGameObject <PrefabCoin> (&player->transform, Vector2(128.f, 0.f));
	auto test2 = AddGameObject <PrefabCoin> (&test1->transform, Vector2(128.f, 0.f));

	std::vector<Vector2> posVec;
	posVec.push_back (Vector2 (-128.f, 128.f));
	posVec.push_back (Vector2 (128.f, 128.f));
	posVec.push_back (Vector2 (-128.f, -128.f));
	posVec.push_back (Vector2 (128.f, -128.f));

	auto scoreObj = AddGameObject <PrefabScore> ();
	auto score = scoreObj->GetComponent<Score> ();

	for (size_t i = 0; i < posVec.size() * 1; ++i)
	{
		int index = i % posVec.size ();
		const auto& pos = posVec[index];
		AddGameObject <PrefabCoin> (pos);
	}

	//Add Debug Object
	auto debug = AddGameObject <GameObject> (Vector2(0, 64));
	debug->transform.SetSpace (Transform::Space::SCREEN);
	debug->transform.SetPivot (Transform::Pivot::TOPLEFT);
	auto fontMesh = debug->AddComponent<FontMesh> ();
	fontMesh->font.color = Color (255, 0, 0);
	fontMesh->font.height = 12;
	fontMesh->SetSize (200.f, 32.f);
	debug->AddComponent<DebugInfo> ();
}
