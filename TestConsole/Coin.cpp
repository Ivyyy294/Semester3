#include "Coin.h"
#include "IvyyyEventSystem.h"

void Coin::OnTriggerEnter ()
{
	gameObject->SetActive (false);
	EventSystem::Me ()->Event ("coin").Invoke();
}
