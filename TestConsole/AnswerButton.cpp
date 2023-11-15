#include "AnswerButton.h"
#include "IvyyyTime.h"
#include "IvyyyEventSystem.h"

using namespace Ivyyy;

void AnswerButton::Start ()
{
	fontMesh = gameObject->GetComponent<FontMesh> ().get();
	fontMesh->font.color = Color (255, 255, 255);
}

void AnswerButton::OnMouseDown ()
{
	if (!event.empty ())
		EventSystem::Me ()->Event (event).Invoke ();

	gameObject->SetActive (false);
}

void AnswerButton::OnMouseEnter ()
{
	fontMesh->font.color = Color (0, 255, 0);
}

void AnswerButton::OnMouseExit ()
{
	fontMesh->font.color = Color (255, 255, 255);
}



