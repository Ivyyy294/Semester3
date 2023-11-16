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
	EventSystem::Me ()->Event ("Back").Bind <PageController, &PageController::OnBack> (this);
	EventSystem::Me ()->Event ("Answer1").Bind <PageController, &PageController::OnAnswer1> (this);
	EventSystem::Me ()->Event ("Answer2").Bind <PageController, &PageController::OnAnswer2> (this);
	EventSystem::Me ()->Event ("Answer3").Bind <PageController, &PageController::OnAnswer3> (this);
	EventSystem::Me ()->Event ("Answer4").Bind <PageController, &PageController::OnAnswer4> (this);
	EventSystem::Me ()->Event ("Exit").Bind <PageController, &PageController::OnExit> (this);
	EventSystem::Me ()->Event ("Reset").Bind <PageController, &PageController::OnReset> (this);

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

	//Raum 1 start
	firstHallway->SetDrawing (Drawings::GetFirstHallway());
	firstHallway->SetText (L"You are standing in the hallway. The way to the left is pitch black.\nThe way to the right looks damaged.");
	pageGraph.AddEdge (firstHallway, darkHallway, L"left");
	pageGraph.AddEdge (firstHallway, dmgHallway, L"right");

	//damaged hallway
	dmgHallway->SetDrawing (Drawings::GetDmgHallway());
	dmgHallway->SetText (L"You are standing in the damaged hallway. At the inner wall is a red door and\nyou can hear water in the distance.");
	pageGraph.AddEdge( dmgHallway, waterHallway ,L"water");
	pageGraph.AddEdge( dmgHallway, redDoor, L"door");

	//Dark hallway
	darkHallway->SetDrawing (Drawings::GetDarkHallway());
	darkHallway->SetText (L"You can't see a thing, but there is something that feels like a door.");
	pageGraph.AddEdge(darkHallway, maintenance, L"door");
	pageGraph.AddEdge(darkHallway, managementRoom, L"continue");

	//Water hallway
	waterHallway->SetDrawing (Drawings::GetWaterHallway());
	waterHallway->SetText (L"The corridor in front of you is waist-deep in water, only a few crates stick out.");
	pageGraph.AddEdge (waterHallway, controlRoom, L"climb");
	pageGraph.AddEdge (waterHallway, cable, L"swim");

	//RedDoor
	redDoor->SetDrawing (Drawings::GetBlockedDrawing());
	redDoor->SetText (L"The door is disabled and everything behind is lost to space...");

	//controlRoom
	controlRoom->SetDrawing (Drawings::GetControlRoom());
	controlRoom->SetText (L"You are standing in the control room. All the computers are flashing red.\nAt the inner wall is a blue door and you can hear a distorted voice in the distance.");
	pageGraph.AddEdge(controlRoom, commonRoom, L"voice");
	pageGraph.AddEdge(controlRoom, maintenance, L"door");
	pageGraph.AddEdge(controlRoom, commandRoomComputer, L"computer");

	//cable
	cable->SetActionEvent ("Reset");
	cable->SetDrawing (Drawings::GetDeadDrawing());
	cable->SetText (L"You try to swim through the water, when suddenly a sparking cable falls from the ceiling.\nYou feel only a sharp pain, then everything goes black.\n\nDo you want to try again?");
	pageGraph.AddEdge (cable, exit, L"exit");
	pageGraph.AddEdge (cable, menu, L"menu");
	pageGraph.AddEdge (cable, bedroom, L"again");

	//maintenance
	maintenance->SetDrawing (Drawings::GetMaintenance());
	maintenance->SetText (L"You enter the maintenance room, in a corner stands an old dusty drink machine.\nAdditionally you can see a red door,a yellow door, a green door and a blue door.");

	PageEdge::Ptr aVenMaBroke = pageGraph.AddEdge (maintenance, vendingMachineBroke, L"machine");
	aVenMaBroke->SetVisibleCondition (&Inventory::GetMachineNotRepaired);	

	PageEdge::Ptr aVenMa = pageGraph.AddEdge (maintenance, vendingMachine, L"machine");
	aVenMa->SetVisibleCondition (&Inventory::GetMachineRepaired);

	pageGraph.AddEdge (maintenance, controlRoom, L"blue");
	pageGraph.AddEdge (maintenance, managementRoom, L"green");
	pageGraph.AddEdge (maintenance, darkHallway, L"yellow");
	pageGraph.AddEdge (maintenance, redDoor, L"red");

	//commonRoom
	commonRoom->SetDrawing (Drawings::GetCommonRoom());
	commonRoom->SetText (L"You enter the common room. The station AI demands everyone to evacuate immediately!\nAll but one escape pod are already gone!");
	
	PageEdge::Ptr enterPod = pageGraph.AddEdge (maintenance, pod, L"pod");
	enterPod->SetLockCondition (&Inventory::GetKey, L"Damn! You can't use them! It is reserved for the management!");
	
	pageGraph.AddEdge (commonRoom, food, L"inspect");

	//Management
	managementRoom->SetDrawing (Drawings::GetMRoom());
	managementRoom->SetText (L"You enter the administration office and find a body lying next to an closed airlock.\nAt the inner wall is a green door.");
	pageGraph.AddEdge (managementRoom, airlock, L"airlock");
	pageGraph.AddEdge (managementRoom, body, L"body");
	pageGraph.AddEdge (managementRoom, maintenance, L"door");

	//Airlock
	airlock->SetActionEvent ("Reset");
	airlock->SetDrawing (Drawings::GetDeadDrawing());
	airlock->SetText (L"You press the red button and with a loud bang you are hurled into space.\nSlowly you choke on your silent screams.\n\nDo you want to try again?");
	pageGraph.AddEdge (airlock, exit, L"exit");
	pageGraph.AddEdge (airlock, menu, L"menu");
	pageGraph.AddEdge (airlock, bedroom, L"again");

	//Body
	body->SetDrawing (Drawings::GetIDCard());
	body->SetText (L"Oh no! It is the CEO and he is dead.\nGuess he won't need his ID-Card any more...");
	body->SetActionEvent ("Key");

	//Pod
	pod->SetDrawing (Drawings::GetEscapePod());
	pod->SetText (L"You enter the escape pod and to your absolute relief, everything seems to be working.");
	PageEdge::Ptr aNoFood = pageGraph.AddEdge (pod, inspectPodNoFood, L"inspect");
	aNoFood->SetVisibleCondition (&Inventory::GetLoose);

	PageEdge::Ptr aFood = pageGraph.AddEdge (pod, inspectPodFood, L"inspect");
	aFood->SetVisibleCondition (&Inventory::GetWin);

	PageEdge::Ptr aWin = pageGraph.AddEdge (pod, win, L"escape");
	aWin->SetVisibleCondition (&Inventory::GetWin);

	PageEdge::Ptr aStarve = pageGraph.AddEdge (pod, starve, L"escape");
	aStarve->SetVisibleCondition (&Inventory::GetLoose);

	inspectPodNoFood->SetDrawing (Drawings::GetEscapePod());
	inspectPodNoFood->SetText (L"With a closer look you notice that there is no water and no food...");

	inspectPodFood->SetDrawing (Drawings::GetEscapePod());
	inspectPodFood->SetText (L"With a closer look you notice that there is no water and no food...\nLuckily you already found something!");

	//Picture
	picture->SetDrawing (Drawings::GetPicture());
	picture->SetText (L"The room is devastated, but you can still see the picture from your graduation,\ntogether with Prof. Dr. Gundolf S. Freyermuth and Prof. Björn Bartholdy.\nGood old times...");

	//Computer
	commandRoomComputer->SetDrawing (Drawings::GetComputer());
	commandRoomComputer->SetText (L"You check the computer and man.... everything is on fire!");

	//Food
	food->SetDrawing (Drawings::GetFood());
	food->SetActionEvent ("SetFood");
	food->SetText (L"You rummage around in the closets and find a supply of canned goods.\nThis will come in handy.");

	//Win
	win->SetActionEvent ("Reset");
	win->SetDrawing (Drawings::DrawWinScreen());
	win->SetText (L"You did it! You managed to escape just in the nick time and even have enough supplies to hold out until help arrives!");
	pageGraph.AddEdge (win, exit, L"exit");
	pageGraph.AddEdge (win, menu, L"menu");
	pageGraph.AddEdge (win, bedroom, L"again");

	//Starve
	starve->SetActionEvent ("Reset");
	starve->SetDrawing (Drawings::GetDeadDrawing());
	starve->SetText (L"You manage to escape from the station, but to your horror there are not enough supplies...\nBy the time rescue arrives, you have long since starved to death...");
	pageGraph.AddEdge (starve, exit, L"exit");
	pageGraph.AddEdge (starve, menu, L"menu");
	pageGraph.AddEdge (starve, bedroom, L"again");

	//Vending Machine Broke
	vendingMachineBroke->SetHistorie (false);
	vendingMachineBroke->SetDrawing (Drawings::DrawVendingMachine());
	vendingMachineBroke->SetText (L"The vending machine seems to be out of order...\nBut there are still a few drinks inside.");

	PageEdge::Ptr aRepair = pageGraph.AddEdge (vendingMachineBroke, repair, L"repair");
	aRepair->SetLockCondition (&Inventory::GetRepairPossible, L"It's hopeless, the motherboard is fried...");

	//Vending Machine
	vendingMachine->SetHistorie (false);
	vendingMachine->SetText (L"The old vending machine seems to be working again!");
	vendingMachine->SetDrawing (Drawings::DrawVendingMachine());
	pageGraph.AddEdge (vendingMachine, water, L"use");

	//Repair
	repair->SetHistorie (false);
	repair->SetDrawing (Drawings::DrawVendingMachine());
	repair->SetText (L"You take a look at the machine and notice some broken cable.\nDo you want to fix the black cable first or the yellow?");
	pageGraph.AddEdge (repair, yellowCable, L"yellow");
	pageGraph.AddEdge (repair, blackCable, L"black");

	repair->SetHistorie (false);
	water->SetDrawing (Drawings::DrawVendingMachine());
	water->SetText (L"You manage to get some bottles of water!");
	water->SetActionEvent ("SetWater");

	yellowCable->SetHistorie (false);
	yellowCable->SetDrawing (Drawings::DrawVendingMachine());
	yellowCable->SetText (L"You fix the cable and the vending machine comes back to live!");
	yellowCable->SetActionEvent ("SetMachineRepaired");
	pageGraph.AddEdge (yellowCable, water, L"use");

	blackCable->SetHistorie (false);
	blackCable->SetDrawing (Drawings::DrawVendingMachine());
	blackCable->SetText (L"You fix the black cable.... and BAAAAANG!\nShoot...the motherboard is fried....");
	blackCable->SetActionEvent ("SetMachineDestroyed");

	currentPage = menu;
}

void PageController::OnAnswer1 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	pageHistory.push (currentPage);
	LoadPage (edges[0]->GetNode());
}

void PageController::OnAnswer2 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	pageHistory.push (currentPage);
	LoadPage (edges[1]->GetNode ());
}

void PageController::OnAnswer3 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	pageHistory.push (currentPage);
	LoadPage (edges[2]->GetNode ());
}

void PageController::OnAnswer4 ()
{
	auto edges = pageGraph.GetEdges (currentPage);
	pageHistory.push (currentPage);
	LoadPage (edges[3]->GetNode ());
}

void PageController::OnExit ()
{
	Ivyyy::IvyyyEngine::Exit ();
}

void PageController::OnBack ()
{
	PageNode::Ptr tmp = pageHistory.top ();
	pageHistory.pop ();
	LoadPage (tmp);
}

void PageController::OnReset ()
{
	pageHistory = std::stack<PageNode::Ptr> ();
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

		//Back Button
		if (pageHistory.empty ())
			buttonController->DisableButton (0);
		else
			buttonController->ActivateButton (0, L"[ Back ]");

		auto edges = pageGraph.GetEdges (page);
		size_t answerCount = edges.size ();
		
		for (size_t i = 0; i < answerCount; ++i)
		{
			PageEdge::Ptr edge = edges[i];
			buttonController->ActivateButton (i + 1, L"[ " + edge->GetName () + L" ]");
		}

		for (size_t i = answerCount + 1; i <= 6; ++i)
			buttonController->DisableButton (i);

		currentPage = page;
	}
}
