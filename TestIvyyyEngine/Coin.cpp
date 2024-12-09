#include "Coin.h"
#include "IvyyyEventSystem.h"
#include "IvyyyDebug.h"

void Coin::OnTriggerEnter ()
{
	gameObject->SetActive (false);
	EventSystem::Me ()->Event ("coin").Invoke();
}

void Coin::OnDisable()
{
	Debug::Log("Coin disabled!");
}

void Coin::OnEnable()
{
	Debug::Log("Coin Spawned!");
}
