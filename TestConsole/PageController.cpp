#include "PageController.h"
#include "Drawings.h"
#include "PageEdge.h"
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
	//Create Pages
	PageNode::Ptr menu = pageGraph.AddNode ();
	PageNode::Ptr exit = pageGraph.AddNode ();
	PageNode::Ptr bedroom = pageGraph.AddNode ();
	PageNode::Ptr firstHallway = pageGraph.AddNode ();
	PageNode::Ptr dmgHallway = pageGraph.AddNode ();
	PageNode::Ptr darkHallway = pageGraph.AddNode ();
	PageNode::Ptr waterHallway = pageGraph.AddNode ();
	PageNode::Ptr redDoor = pageGraph.AddNode ();
	PageNode::Ptr controlRoom = pageGraph.AddNode ();
	PageNode::Ptr cable = pageGraph.AddNode ();
	PageNode::Ptr maintenance = pageGraph.AddNode ();
	PageNode::Ptr commonRoom = pageGraph.AddNode ();
	PageNode::Ptr managementRoom = pageGraph.AddNode ();
	PageNode::Ptr airlock = pageGraph.AddNode ();
	PageNode::Ptr body = pageGraph.AddNode ();
	PageNode::Ptr pod = pageGraph.AddNode ();
	PageNode::Ptr picture = pageGraph.AddNode ();
	PageNode::Ptr commandRoomComputer = pageGraph.AddNode ();
	PageNode::Ptr food = pageGraph.AddNode ();
	PageNode::Ptr inspectPodNoFood = pageGraph.AddNode ();
	PageNode::Ptr win = pageGraph.AddNode ();
	PageNode::Ptr starve = pageGraph.AddNode ();
	PageNode::Ptr inspectPodFood = pageGraph.AddNode ();
	PageNode::Ptr vendingMachineBroke = pageGraph.AddNode ();
	PageNode::Ptr vendingMachine = pageGraph.AddNode ();
	PageNode::Ptr water = pageGraph.AddNode ();
	PageNode::Ptr repair = pageGraph.AddNode ();
	PageNode::Ptr yellowCable = pageGraph.AddNode ();
	PageNode::Ptr blackCable = pageGraph.AddNode ();

	//Menu
	menu->SetDrawing (Drawings::Menu ());
	menu->SetText (L"Do you want to play or do you want to exit?");
	menu->SetActionEvent ("Reset");

	//pageGraph.AddEdge (menu, exit, L"exit");
	//pageGraph.AddEdge (menu, bedroom, L"play");

	currentPage = menu;
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

void PageController::LoadPage (PageNode::Ptr page)
{
	if (page != nullptr)
	{
		prefabDrawing->SetDrawing (page->GetDrawing());
		textMesh->text = page->GetText ();

		//auto edges = pageGraph.GetEdges (page);
		//size_t answerCount = edges.size ();
		//
		//for (size_t i = 0; i < answerCount; ++i)
		//{
		//	PageEdge::Ptr edge = edges[i];
		//	buttonController->ActivateButton (i, edge->GetName());
		//}

		size_t answerCount = 0;

		for (size_t i = answerCount; i < 4; ++i)
			buttonController->DisableButton (i);

		currentPage = page;
	}
}
