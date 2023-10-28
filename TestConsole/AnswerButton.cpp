#include "AnswerButton.h"
#include "IvyyyTime.h"

using namespace Ivyyy;

void AnswerButton::Start ()
{
	fontMesh = gameObject->GetComponent<FontMesh> ().get();
	fontMesh->font.color = Color (255, 255, 255);
}

void AnswerButton::OnMouseDown ()
{
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



