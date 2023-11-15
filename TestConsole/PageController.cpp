#include "PageController.h"
#include "Drawings.h"
#include "IvyyyEventSystem.h"

PageController::PageController ()
{
	InitPageGraph ();
}

void PageController::Start ()
{
	//Register Events
	EventSystem::Me ()->Event ("Answer1").Bind <PageController, &PageController::OnAnswer1> (this);
	EventSystem::Me ()->Event ("Answer2").Bind <PageController, &PageController::OnAnswer2> (this);
	EventSystem::Me ()->Event ("Answer3").Bind <PageController, &PageController::OnAnswer3> (this);
	EventSystem::Me ()->Event ("Answer4").Bind <PageController, &PageController::OnAnswer4> (this);

	LoadPage (currentPage);
}

void PageController::InitPageGraph ()
{
	PageNode& menu = pageGraph.AddNode ();
	menu.SetDrawing (Drawings::Menu ());
	menu.SetText (L"Do you want to play or do you want to exit?");
	menu.SetActionEvent ("Reset");

	currentPage = &menu;
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

void PageController::LoadPage (PageNode* page)
{
	if (page != nullptr)
	{
		prefabDrawing->SetDrawing (page->GetDrawing());
		textMesh->text = page->GetText ();
		currentPage = page;
	}
}
