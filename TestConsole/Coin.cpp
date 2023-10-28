#include "Coin.h"

void Coin::OnTriggerEnter ()
{
	gameObject->SetActive (false);
	score->score++;
}
