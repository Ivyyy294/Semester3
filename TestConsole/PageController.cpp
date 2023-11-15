#include "PageController.h"

#include "IvyyyEventSystem.h"

void PageController::Start ()
{
	//Register Events
	EventSystem::Me ()->Event ("Answer1").Bind <PageController, &PageController::OnAnswer1> (this);
	EventSystem::Me ()->Event ("Answer2").Bind <PageController, &PageController::OnAnswer2> (this);
	EventSystem::Me ()->Event ("Answer3").Bind <PageController, &PageController::OnAnswer3> (this);
	EventSystem::Me ()->Event ("Answer4").Bind <PageController, &PageController::OnAnswer4> (this);
}

void PageController::OnAnswer1 ()
{
}

void PageController::OnAnswer2 ()
{
}

void PageController::OnAnswer3 ()
{
}

void PageController::OnAnswer4 ()
{
}

void PageController::LoadPage (int pageId)
{

}
