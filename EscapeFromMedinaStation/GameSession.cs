using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;

namespace EscapeFromMedinaStation
{
	public class GameSession
	{
		public Stack<byte> pageHistorie = new Stack<byte>();
		private Dictionary<byte, Page> pageMap = new Dictionary<byte, Page>();
		private byte currentPage = 254;
		private GameValues gameValues = new GameValues();
		protected Socket socket;

		//Public Functions
		public GameSession (Socket _socket)
		{
			socket = _socket;
			InitContent();
		}

		public virtual void Run() { }
		public virtual void Frame() { }

		public void SetCurrentPage(byte newPage)
		{
			if (GetCurrentPage().GetHistorie())
				pageHistorie.Push(currentPage);
			currentPage = newPage;
		}

		public byte GetCurrentPageId()
		{
			return currentPage;
		}

		//Protected
		protected Page GetCurrentPage() { return pageMap[currentPage]; }

		protected void GoBack()
		{
			if (pageHistorie.Count > 0)
				currentPage = pageHistorie.Pop();
			else
				currentPage = 0;
		}

		protected bool GoingBackAvailable()
		{
			if (pageHistorie.Count == 0)
				return false;
			else
			{
				return pageHistorie.Peek() != 254;
			}
		}

		//Private Functions
		void AddPage (Page p) { pageMap.Add(p.GetPageId(), p);}

		void ResetGame()
		{
			pageHistorie.Clear();
			currentPage = 254;
			gameValues.ResetGameValues();
		}

		void InitContent()
		{
			Page menu = new Page(254);
			Page bedroom = new Page(0);
			Page firstHallway = new Page(1);
			Page dmgHallway = new Page(2);
			Page darkHallway = new Page(3);
			Page waterHallway = new Page(4);
			Page redDoor = new Page(5);
			Page controlRoom = new Page(6);
			Page cable = new Page(7);
			Page maintenance = new Page(8);
			Page commonRoom = new Page(9);
			Page managementRoom = new Page(10);
			Page airlock = new Page(11);
			Page body = new Page(12);
			Page pod = new Page(13);
			Page picture = new Page(14);
			Page commandRoomComputer = new Page(16);
			Page food = new Page(17);
			Page inspectPodNoFood = new Page(18);
			Page win = new Page(19);
			Page starve = new Page(20);
			Page inspectPodFood = new Page(21);
			Page vendingMachineBroke = new Page(22);
			Page vendingMachine = new Page(23);
			Page water = new Page(24);
			Page repair = new Page(25);
			Page yellowCable = new Page(26);
			Page blackCable = new Page(27);

			//Menu
			menu.SetAction (ResetGame);
			menu.SetDecoration (Drawings.GetMenuDrawing);
			menu.SetContent("Do you want to play or do you want to exit?");
			menu.AddAnswer("exit", 255);
			menu.AddAnswer("play", bedroom.GetPageId());
			AddPage(menu);

			//bedroom
			bedroom.SetDecoration(Drawings.GetBedroom);
			bedroom.SetContent ("You are standing inside your room. The alarm is throbbing in your head.\nYour vision is blurred, but you can see a door in front of you");
			bedroom.AddAnswer("door", firstHallway.GetPageId());
			bedroom.AddAnswer("inspect", picture.GetPageId());
			AddPage(bedroom);

			//Raum 1 start
			firstHallway.SetDecoration(Drawings.GetFirstHallway);
			firstHallway.SetContent ("You are standing in the hallway. The way to the left is pitch black.\nThe way to the right looks damaged.");
			firstHallway.AddAnswer ("right", 2);
			firstHallway.AddAnswer("left", 3);
			AddPage(firstHallway);

			//damaged hallway
			dmgHallway.SetDecoration(Drawings.GetDmgHallway);
			dmgHallway.SetContent("You are standing in the damaged hallway. At the inner wall is a red door and\n"
			 + "you can hear water in the distance.");
			dmgHallway.AddAnswer("water", waterHallway.GetPageId());
			dmgHallway.AddAnswer("door", redDoor.GetPageId());
			AddPage(dmgHallway);

			//Dark hallway
			darkHallway.SetDecoration(Drawings.GetDarkHallway);
			darkHallway.SetContent("You can't see a thing, but there is something that feels like a door.");
			darkHallway.AddAnswer("door", maintenance.GetPageId());
			darkHallway.AddAnswer("continue", managementRoom.GetPageId());
			AddPage(darkHallway);

			//Water hallway
			waterHallway.SetDecoration(Drawings.GetWaterHallway);
			waterHallway.SetContent("The corridor in front of you is waist-deep in water, only a few crates stick out.");
			waterHallway.AddAnswer("climb", controlRoom.GetPageId());
			waterHallway.AddAnswer("swim", cable.GetPageId());
			AddPage(waterHallway);

			//RedDoor
			redDoor.SetDecoration(Drawings.GetBlockedDrawing);
			redDoor.SetContent("The door is disabled and everything behind is lost to space...");
			AddPage(redDoor);

			//controlRoom
			controlRoom.SetDecoration(Drawings.GetControlRoom);
			controlRoom.SetContent("You are standing in the control room. All the computers are flashing red.\n"
				+ "At the inner wall is a blue door and you can hear a distorted voice in the distance.");
			controlRoom.AddAnswer("voice", commonRoom.GetPageId());
			controlRoom.AddAnswer("door", maintenance.GetPageId());
			controlRoom.AddAnswer("computer", commandRoomComputer.GetPageId());
			AddPage(controlRoom);

			//cable
			cable.SetAction (ResetGame);
			cable.SetDecoration(Drawings.GetDeadDrawing);
			cable.SetContent("You try to swim through the water, when suddenly a sparking cable falls from the ceiling.\n"
				+ "You feel only a sharp pain, then everything goes black.\n\n"
				+ "Do you want to try again?");
			cable.AddAnswer("exit", 255);
			cable.AddAnswer("menu", menu.GetPageId());
			cable.AddAnswer("again", bedroom.GetPageId());
			AddPage(cable);

			//maintenance
			maintenance.SetDecoration(Drawings.GetMaintenance);
			maintenance.SetContent("You enter the maintenance room, in a corner stands an old dusty drink machine.\nAdditionally you can see a red door,a yellow door, a green door and a blue door.");

			Answer aVenMaBroke = new Answer("machine", vendingMachineBroke.GetPageId());
			aVenMaBroke.SetVisibleCondition(gameValues.GetMachineNotRepaired);
			maintenance.AddAnswer(aVenMaBroke);

			Answer aVenMa = new Answer("machine", vendingMachine.GetPageId());
			aVenMa.SetVisibleCondition(gameValues.GetMachineRepaired);
			maintenance.AddAnswer(aVenMa);

			maintenance.AddAnswer("blue", controlRoom.GetPageId());
			maintenance.AddAnswer("green", managementRoom.GetPageId());
			maintenance.AddAnswer("yellow", darkHallway.GetPageId());
			maintenance.AddAnswer("red", redDoor.GetPageId());
			AddPage(maintenance);

			//commonRoom
			commonRoom.SetDecoration(Drawings.GetCommonRoom);
			commonRoom.SetContent("You enter the common room. The station AI demands everyone to evacuate immediately!\n"
			+ "All but one escape pod are already gone!");
			Answer enterPod = new Answer("pod", pod.GetPageId());
			enterPod.SetLockCondition(gameValues.CheckKey, "Damn! You can't use them! It is reserved for the management!");
			commonRoom.AddAnswer(enterPod);
			commonRoom.AddAnswer("inspect", food.GetPageId());
			AddPage(commonRoom);

			//Management
			managementRoom.SetDecoration(Drawings.GetMRoom);
			managementRoom.SetContent("You enter the administration office and find a body lying next to an closed airlock.\nAt the inner wall is a green door.");
			managementRoom.AddAnswer("airlock", airlock.GetPageId());
			managementRoom.AddAnswer("body", body.GetPageId());
			managementRoom.AddAnswer("door", maintenance.GetPageId());
			AddPage(managementRoom);

			//Airlock
			airlock.SetAction (ResetGame);
			airlock.SetDecoration(Drawings.GetDeadDrawing);
			airlock.SetContent("You press the red button and with a loud bang you are hurled into space.\n"
			+ "Slowly you choke on your silent screams.\n\n"
			+ "Do you want to try again?");
			airlock.AddAnswer("exit", 255);
			airlock.AddAnswer("menu", menu.GetPageId());
			airlock.AddAnswer("again", bedroom.GetPageId());
			AddPage(airlock);

			//Body
			body.SetDecoration(Drawings.GetIDCard);
			body.SetContent("Oh no! It is the CEO and he is dead.\nGuess he won't need his ID-Card any more...");
			body.SetAction(gameValues.SetKey);
			AddPage(body);

			//Pod
			pod.SetDecoration(Drawings.GetEscapePod);
			pod.SetContent("You enter the escape pod and to your absolute relief, everything seems to be working.");
			Answer aNoFood = new Answer ("inspect", inspectPodNoFood.GetPageId());
			aNoFood.SetVisibleCondition(gameValues.GetLoose);
			pod.AddAnswer(aNoFood);

			Answer aFood = new Answer("inspect", inspectPodFood.GetPageId());
			aFood.SetVisibleCondition(gameValues.GetWin);
			pod.AddAnswer(aFood);

			Answer aWin = new Answer("escape", win.GetPageId());
			aWin.SetVisibleCondition(gameValues.GetWin);
			pod.AddAnswer(aWin);

			Answer aStarve = new Answer("escape", starve.GetPageId());
			aStarve.SetVisibleCondition(gameValues.GetLoose);
			pod.AddAnswer(aStarve);
			AddPage(pod);

			inspectPodNoFood.SetDecoration(Drawings.GetEscapePod);
			inspectPodNoFood.SetContent("With a closer look you notice that there is no water and no food...");
			AddPage(inspectPodNoFood);

			inspectPodFood.SetDecoration(Drawings.GetEscapePod);
			inspectPodFood.SetContent("With a closer look you notice that there is no water and no food...\nLuckily you already found something!");
			AddPage(inspectPodFood);

			//Picture
			picture.SetDecoration(Drawings.GetPicture);
			picture.SetContent("The room is devastated, but you can still see the picture from your graduation,\ntogether with Prof. Dr. Gundolf S. Freyermuth and Prof. Björn Bartholdy.\nGood old times...");
			AddPage(picture);

			//Computer
			commandRoomComputer.SetDecoration(Drawings.GetComputer);
			commandRoomComputer.SetContent("You check the computer and man.... everything is on fire!");
			AddPage(commandRoomComputer);

			//Food
			food.SetDecoration(Drawings.GetFood);
			food.SetAction(gameValues.SetFood);
			food.SetContent("You rummage around in the closets and find a supply of canned goods.\n"
				+ "This will come in handy.");
			AddPage(food);

			//Win
			win.SetAction (ResetGame);
			win.SetDecoration(Drawings.DrawWinScreen);
			win.SetContent("You did it! You managed to escape just in the nick time and even have enough supplies to hold out until help arrives!");
			win.AddAnswer("exit", 255);
			win.AddAnswer("menu", menu.GetPageId());
			win.AddAnswer("again", bedroom.GetPageId());
			AddPage(win);

			//Starve
			starve.SetAction(ResetGame);
			starve.SetDecoration(Drawings.GetDeadDrawing);
			starve.SetContent("You manage to escape from the station, but to your horror there are not enough supplies...\n"
				+ "By the time rescue arrives, you have long since starved to death...");
			starve.AddAnswer("exit", 255);
			starve.AddAnswer("menu", menu.GetPageId());
			starve.AddAnswer("again", bedroom.GetPageId());
			AddPage(starve);

			vendingMachineBroke.SetHistorie (false);
			vendingMachineBroke.SetContent ("The vending machine seems to be out of order...\nBut there are still a few drinks inside.");
			vendingMachineBroke.SetDecoration(Drawings.DrawVendingMachine);
			Answer aRepair = new Answer("repair", repair.GetPageId());
			aRepair.SetLockCondition (gameValues.GetRepairPossible, "It's hopeless, the motherboard is fried...");
			vendingMachineBroke.AddAnswer (aRepair);
			AddPage(vendingMachineBroke);

			vendingMachine.SetHistorie(false);
			vendingMachine.SetContent("The old vending machine seems to be working again!");
			vendingMachine.SetDecoration(Drawings.DrawVendingMachine);
			vendingMachine.AddAnswer("use", water.GetPageId());
			AddPage(vendingMachine);

			repair.SetHistorie(false);
			repair.SetDecoration(Drawings.DrawVendingMachine);
			repair.SetContent ("You take a look at the machine and notice some broken cable.\nDo you want to fix the black cable first or the yellow?");
			repair.AddAnswer("yellow", yellowCable.GetPageId());
			repair.AddAnswer("black", blackCable.GetPageId());
			AddPage(repair);

			repair.SetHistorie(false);
			water.SetDecoration(Drawings.DrawVendingMachine);
			water.SetContent("You manage to get some bottles of water!");
			water.SetAction(gameValues.SetWater);
			AddPage(water);

			yellowCable.SetHistorie(false);
			yellowCable.SetDecoration(Drawings.DrawVendingMachine);
			yellowCable.SetContent("You fix the cable and the vending machine comes back to live!");
			yellowCable.SetAction(gameValues.SetMachineRepaired);
			yellowCable.AddAnswer("use", water.GetPageId());
			AddPage(yellowCable);

			blackCable.SetHistorie(false);
			blackCable.SetDecoration(Drawings.DrawVendingMachine);
			blackCable.SetContent("You fix the black cable.... and BAAAAANG!\nShoot...the motherboard is fried....");
			blackCable.SetAction(gameValues.SetRepairPosible);
			AddPage(blackCable);
		}
	}
}
