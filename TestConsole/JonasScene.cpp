#include "JonasScene.h"
#include "Player.h"
#include "PrefabCoin.h"
#include "PrefabScore.h"
#include "Score.h"
#include "Coin.h"

void JonasScene::Init ()
{
	auto player = AddGameObject <Player> ();
	//auto test1 = AddGameObject <PrefabCoin> ();
	//test1->transform.GetLocalPosition ().x = 128.f;
	//test1->SetParent (player.get());
	//auto test2 = AddGameObject <PrefabCoin> ();
	//test2->transform.GetLocalPosition ().x = 128;
	//test2->SetParent (test1.get ());

	std::vector<Vector2> posVec;
	posVec.push_back (Vector2 (-128.f, 128.f));
	posVec.push_back (Vector2 (128.f, 128.f));
	posVec.push_back (Vector2 (-128.f, -128.f));
	posVec.push_back (Vector2 (128.f, -128.f));

	auto scoreObj = AddGameObject <PrefabScore> ();
	auto score = scoreObj->GetComponent<Score> ();

	for (const auto & i : posVec)
	{
		auto coin = AddGameObject <PrefabCoin> ();
		coin->transform.SetPosition (i);
		coin->GetComponent<Coin> ()->score = score.get();
	}

}
