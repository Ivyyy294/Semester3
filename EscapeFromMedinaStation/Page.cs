using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;

namespace EscapeFromMedinaStation
{
	public class Page
	{
		static private Dictionary<byte, Page> pageMap = new Dictionary<byte, Page>();
		
		static public void InitContent()
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
			menu.SetAction(GameValues.ResetGameValues);
			menu.SetDecoration (Drawings.GetMenuDrawing);
			menu.SetContent("Do you want to play or do you want to exit?");
			menu.AddAnswer("exit", 255);
			menu.AddAnswer("play", bedroom.GetPageId());
			Page.AddPage(menu);

			//bedroom
			bedroom.SetDecoration(Drawings.GetBedroom);
			bedroom.SetContent ("You are standing inside your room. The alarm is throbbing in your head.\nYour vision is blurred, but you can see a door in front of you");
			bedroom.AddAnswer("door", firstHallway.GetPageId());
			bedroom.AddAnswer("inspect", picture.GetPageId());
			Page.AddPage(bedroom);

			//Raum 1 start
			firstHallway.SetDecoration(Drawings.GetFirstHallway);
			firstHallway.SetContent ("You are standing in the hallway. The way to the left is pitch black.\nThe way to the right looks damaged.");
			firstHallway.AddAnswer ("right", 2);
			firstHallway.AddAnswer("left", 3);
			Page.AddPage(firstHallway);

			//damaged hallway
			dmgHallway.SetDecoration(Drawings.GetDmgHallway);
			dmgHallway.SetContent("You are standing in the damaged hallway. At the inner wall is a red door and\n"
			 + "you can hear water in the distance.");
			dmgHallway.AddAnswer("water", waterHallway.GetPageId());
			dmgHallway.AddAnswer("door", redDoor.GetPageId());
			Page.AddPage(dmgHallway);

			//Dark hallway
			darkHallway.SetDecoration(Drawings.GetDarkHallway);
			darkHallway.SetContent("You can't see a thing, but there is something that feels like a door.");
			darkHallway.AddAnswer("door", maintenance.GetPageId());
			darkHallway.AddAnswer("continue", managementRoom.GetPageId());
			Page.AddPage(darkHallway);

			//Water hallway
			waterHallway.SetDecoration(Drawings.GetWaterHallway);
			waterHallway.SetContent("The corridor in front of you is waist-deep in water, only a few crates stick out.");
			waterHallway.AddAnswer("climb", controlRoom.GetPageId());
			waterHallway.AddAnswer("swim", cable.GetPageId());
			Page.AddPage(waterHallway);

			//RedDoor
			redDoor.SetDecoration(Drawings.GetBlockedDrawing);
			redDoor.SetContent("The door is disabled and everything behind is lost to space...");
			Page.AddPage(redDoor);

			//controlRoom
			controlRoom.SetDecoration(Drawings.GetControlRoom);
			controlRoom.SetContent("You are standing in the control room. All the computers are flashing red.\n"
				+ "At the inner wall is a blue door and you can hear a distorted voice in the distance.");
			controlRoom.AddAnswer("voice", commonRoom.GetPageId());
			controlRoom.AddAnswer("door", maintenance.GetPageId());
			controlRoom.AddAnswer("computer", commandRoomComputer.GetPageId());
			Page.AddPage(controlRoom);

			//cable
			cable.SetAction(GameValues.ResetGameValues);
			cable.SetDecoration(Drawings.GetDeadDrawing);
			cable.SetContent("You try to swim through the water, when suddenly a sparking cable falls from the ceiling.\n"
				+ "You feel only a sharp pain, then everything goes black.\n\n"
				+ "Do you want to try again?");
			cable.AddAnswer("exit", 255);
			cable.AddAnswer("menu", menu.GetPageId());
			cable.AddAnswer("again", bedroom.GetPageId());
			Page.AddPage(cable);

			//maintenance
			maintenance.SetDecoration(Drawings.GetMaintenance);
			maintenance.SetContent("You enter the maintenance room, in a corner stands an old dusty drink machine.\nAdditionally you can see a red door,a yellow door, a green door and a blue door.");

			Answer aVenMaBroke = new Answer("machine", vendingMachineBroke.GetPageId());
			aVenMaBroke.SetVisibleCondition(GameValues.GetMachineNotRepaired);
			maintenance.AddAnswer(aVenMaBroke);

			Answer aVenMa = new Answer("machine", vendingMachine.GetPageId());
			aVenMa.SetVisibleCondition(GameValues.GetMachineRepaired);
			maintenance.AddAnswer(aVenMa);

			maintenance.AddAnswer("blue", controlRoom.GetPageId());
			maintenance.AddAnswer("green", managementRoom.GetPageId());
			maintenance.AddAnswer("yellow", darkHallway.GetPageId());
			maintenance.AddAnswer("red", redDoor.GetPageId());
			Page.AddPage(maintenance);

			//commonRoom
			commonRoom.SetDecoration(Drawings.GetCommonRoom);
			commonRoom.SetContent("You enter the common room. The station AI demands everyone to evacuate immediately!\n"
			+ "All but one escape pod are already gone!");
			Answer enterPod = new Answer("pod", pod.GetPageId());
			enterPod.SetLockCondition(GameValues.CheckKey, "Damn! You can't use them! It is reserved for the management!");
			commonRoom.AddAnswer(enterPod);
			commonRoom.AddAnswer("inspect", food.GetPageId());
			Page.AddPage(commonRoom);

			//Management
			managementRoom.SetDecoration(Drawings.GetMRoom);
			managementRoom.SetContent("You enter the administration office and find a body lying next to an closed airlock.\nAt the inner wall is a green door.");
			managementRoom.AddAnswer("airlock", airlock.GetPageId());
			managementRoom.AddAnswer("body", body.GetPageId());
			managementRoom.AddAnswer("door", maintenance.GetPageId());
			Page.AddPage(managementRoom);

			//Airlock
			airlock.SetAction(GameValues.ResetGameValues);
			airlock.SetDecoration(Drawings.GetDeadDrawing);
			airlock.SetContent("You press the red button and with a loud bang you are hurled into space.\n"
			+ "Slowly you choke on your silent screams.\n\n"
			+ "Do you want to try again?");
			airlock.AddAnswer("exit", 255);
			airlock.AddAnswer("menu", menu.GetPageId());
			airlock.AddAnswer("again", bedroom.GetPageId());
			Page.AddPage(airlock);

			//Body
			body.SetDecoration(Drawings.GetIDCard);
			body.SetContent("Oh no! It is the CEO and he is dead.\nGuess he won't need his ID-Card any more...");
			body.SetAction(GameValues.SetKey);
			Page.AddPage(body);

			//Pod
			pod.SetDecoration(Drawings.GetEscapePod);
			pod.SetContent("You enter the escape pod and to your absolute relief, everything seems to be working.");
			Answer aNoFood = new Answer ("inspect", inspectPodNoFood.GetPageId());
			aNoFood.SetVisibleCondition(GameValues.GetLoose);
			pod.AddAnswer(aNoFood);

			Answer aFood = new Answer("inspect", inspectPodFood.GetPageId());
			aFood.SetVisibleCondition(GameValues.GetWin);
			pod.AddAnswer(aFood);

			Answer aWin = new Answer("escape", win.GetPageId());
			aWin.SetVisibleCondition(GameValues.GetWin);
			pod.AddAnswer(aWin);

			Answer aStarve = new Answer("escape", starve.GetPageId());
			aStarve.SetVisibleCondition(GameValues.GetLoose);
			pod.AddAnswer(aStarve);
			Page.AddPage(pod);

			inspectPodNoFood.SetDecoration(Drawings.GetEscapePod);
			inspectPodNoFood.SetContent("With a closer look you notice that there is no water and no food...");
			Page.AddPage(inspectPodNoFood);

			inspectPodFood.SetDecoration(Drawings.GetEscapePod);
			inspectPodFood.SetContent("With a closer look you notice that there is no water and no food...\nLuckily you already found something!");
			Page.AddPage(inspectPodFood);

			//Picture
			picture.SetDecoration(Drawings.GetPicture);
			picture.SetContent("The room is devastated, but you can still see the picture from your graduation,\ntogether with Prof. Dr. Gundolf S. Freyermuth and Prof. Björn Bartholdy.\nGood old times...");
			Page.AddPage(picture);

			//Computer
			commandRoomComputer.SetDecoration(Drawings.GetComputer);
			commandRoomComputer.SetContent("You check the computer and man.... everything is on fire!");
			Page.AddPage(commandRoomComputer);

			//Food
			food.SetDecoration(Drawings.GetFood);
			food.SetAction(GameValues.SetFood);
			food.SetContent("You rummage around in the closets and find a supply of canned goods.\n"
				+ "This will come in handy.");
			Page.AddPage(food);

			//Win
			win.SetAction(GameValues.ResetGameValues);
			win.SetDecoration(Drawings.DrawWinScreen);
			win.SetContent("You did it! You managed to escape just in the nick time and even have enough supplies to hold out until help arrives!");
			win.AddAnswer("exit", 255);
			win.AddAnswer("menu", menu.GetPageId());
			win.AddAnswer("again", bedroom.GetPageId());
			Page.AddPage(win);

			//Starve
			starve.SetAction(GameValues.ResetGameValues);
			starve.SetDecoration(Drawings.GetDeadDrawing);
			starve.SetContent("You manage to escape from the station, but to your horror there are not enough supplies...\n"
				+ "By the time rescue arrives, you have long since starved to death...");
			starve.AddAnswer("exit", 255);
			starve.AddAnswer("menu", menu.GetPageId());
			starve.AddAnswer("again", bedroom.GetPageId());
			Page.AddPage(starve);

			vendingMachineBroke.SetHistorie (false);
			vendingMachineBroke.SetContent ("The vending machine seems to be out of order...\nBut there are still a few drinks inside.");
			vendingMachineBroke.SetDecoration(Drawings.DrawVendingMachine);
			Answer aRepair = new Answer("repair", repair.GetPageId());
			aRepair.SetLockCondition (GameValues.GetRepairPossible, "It's hopeless, the motherboard is fried...");
			vendingMachineBroke.AddAnswer (aRepair);
			Page.AddPage(vendingMachineBroke);

			vendingMachine.SetHistorie(false);
			vendingMachine.SetContent("The old vending machine seems to be working again!");
			vendingMachine.SetDecoration(Drawings.DrawVendingMachine);
			vendingMachine.AddAnswer("use", water.GetPageId());
			Page.AddPage(vendingMachine);

			repair.SetHistorie(false);
			repair.SetDecoration(Drawings.DrawVendingMachine);
			repair.SetContent ("You take a look at the machine and notice some broken cable.\nDo you want to fix the black cable first or the yellow?");
			repair.AddAnswer("yellow", yellowCable.GetPageId());
			repair.AddAnswer("black", blackCable.GetPageId());
			Page.AddPage(repair);

			repair.SetHistorie(false);
			water.SetDecoration(Drawings.DrawVendingMachine);
			water.SetContent("You manage to get some bottles of water!");
			water.SetAction(GameValues.SetWater);
			Page.AddPage(water);

			yellowCable.SetHistorie(false);
			yellowCable.SetDecoration(Drawings.DrawVendingMachine);
			yellowCable.SetContent("You fix the cable and the vending machine comes back to live!");
			yellowCable.SetAction(GameValues.SetMachineRepaired);
			yellowCable.AddAnswer("use", water.GetPageId());
			Page.AddPage(yellowCable);

			blackCable.SetHistorie(false);
			blackCable.SetDecoration(Drawings.DrawVendingMachine);
			blackCable.SetContent("You fix the black cable.... and BAAAAANG!\nShoot...the motherboard is fried....");
			blackCable.SetAction(GameValues.SetRepairPosible);
			Page.AddPage(blackCable);
		}
		
		static public Page GetPage (byte id)
		{
			if (pageMap.ContainsKey(id))
				return pageMap[id];
			else 
				return null;
		}

		static public Page GetCurrentPage() { return pageMap[GameValues.GetCurrentPage()]; }

		static public void AddPage (Page p) { pageMap.Add(p.GetPageId(), p);}

		//static public void ShowPage (byte pageNr)
		//{
		//	if (pageMap.ContainsKey(pageNr))
		//		pageMap[pageNr].Run();
		//	else
		//	{
		//		Console.Clear();
		//		Console.WriteLine("ERROR: Page " + pageNr.ToString() + " not found!");
		//		Console.ReadLine();
		//	}
		//}

		private bool historie = true;
		private bool goBackPossible = true;
		private string content = "";
		private Action decoration = null;
		private Action action = null;
		private byte pageId;
		private Stack <Answer> answers = new Stack <Answer> ();

		public Page (byte id)
		{
			pageId = id;
		}

		public void SetHistorie(bool val) { historie = val; }
		public bool GetHistorie() { return historie; }
		public byte GetPageId () { return pageId; }
		//public void SetGoBackPossible(bool val) { goBackPossible = val; }
		public void SetAction (Action a) { action = a; }
		public void SetContent (string c) {content = c;}
		public void SetDecoration (Action a) {decoration = a;}
		public void AddAnswer (Answer a) {answers.Push(a);}
		public void AddAnswer(string text, byte pageNr) { answers.Push(new Answer(text, pageNr)); }
		
		public void RunClient(Socket socket)
		{
			Console.Clear();

			Console.WriteLine("\n\n");

			if (decoration != null)
				decoration();

			Console.WriteLine("");

			Drawings.DrawCenterTextLine (content);

			int cursorPos = Drawings.DrawAnswerButtons(answers, goBackPossible && GameValues.GoingBackAvailable());
			Console.WriteLine("");

			while (true)
			{
				Console.SetCursorPosition(Math.Max (0, cursorPos), Console.CursorTop);
				Console.Write("\\: ");

				string input = Console.ReadLine().ToLower();
				NetworkManager.SendStringData (socket, input);

				byte response = NetworkManager.ReceiveByteData(socket);

				if (response == 0)
					return;
				else if (response == 1)
					Drawings.DrawCenterTextLine("Sorry i didn't understand that!\n");
				else if (response == 2)
					Drawings.DrawCenterTextLine("You can't go back!\n");
			}
		}

		public void RunServer (Socket socket)
		{
			if (action != null)
				action();

			NetworkManager.SendByteData (socket, pageId);

			//Get input
			while (true)
			{
				string input = NetworkManager.ReceiveStringData (socket);

				Console.WriteLine ("Client input: " + input);

				if (input.Contains("back"))
				{
					if (GameValues.GoingBackAvailable())
					{
						GameValues.GoBack();
						NetworkManager.SendByteData (socket, 0); //OK
						return;
					}

					NetworkManager.SendByteData (socket, 2); //You can't go back!
				}
				else
				{
					bool validInput = false;

					foreach (Answer i in answers)
					{
						if (i.IsVisible() && input.Contains(i.GetKeyword()))
						{
							validInput = true;

							if (i.CheckCondition())
							{
								GameValues.SetCurrentPage(i.GetPageNr());
								NetworkManager.SendByteData (socket, 0); //OK
								return;
							}
						}
					}

					if (!validInput)
						NetworkManager.SendByteData (socket, 1); //Sorry i didn't understand that!
				}
			}
		}
	}
}
