#include <IvyyyEngine.h>
#include <IvyyyEventSystem.h>
#include "PageController.h"
#include "Drawings.h"
#include "PageEdge.h"

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
	EventSystem::Me ()->Event ("Exit").Bind <PageController, &PageController::OnExit> (this);

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
	pageGraph.AddEdge (menu, bedroom, L"play");
	pageGraph.AddEdge (menu, exit, L"exit");

	//Exit
	exit->SetActionEvent ("Exit");

	//bedroom
	bedroom->SetDrawing (Drawings::GetBedroom());
	bedroom->SetText (L"You are standing inside your room. The alarm is throbbing in your head.\nYour vision is blurred, but you can see a door in front of you");
	pageGraph.AddEdge (bedroom, firstHallway, L"door");
	pageGraph.AddEdge (bedroom, picture, L"inspect");

	currentPage = menu;
}

void PageController::OnAnswer1 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	LoadPage (edges[0]->GetNode());
}

void PageController::OnAnswer2 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	LoadPage (edges[1]->GetNode ());
}

void PageController::OnAnswer3 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	LoadPage (edges[2]->GetNode ());
}

void PageController::OnAnswer4 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	LoadPage (edges[3]->GetNode ());
}

void PageController::OnExit ()
{
	Ivyyy::IvyyyEngine::Exit ();
}

void PageController::LoadPage (PageNode::Ptr page)
{
	if (page != nullptr)
	{
		const std::string& event = page->GetActionEvent ();

		if (!event.empty())
			Ivyyy::EventSystem::Me ()->Event (event).Invoke ();

		prefabDrawing->SetDrawing (page->GetDrawing());
		textMesh->text = page->GetText ();

		auto edges = pageGraph.GetEdges (page);
		size_t answerCount = edges.size ();
		
		for (size_t i = 0; i < answerCount; ++i)
		{
			PageEdge::Ptr edge = edges[i];
			buttonController->ActivateButton (i, L"[" + edge->GetName () + L"]");
		}

		for (size_t i = answerCount; i < 4; ++i)
			buttonController->DisableButton (i);

		currentPage = page;
	}
}
