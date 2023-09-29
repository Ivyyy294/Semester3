using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeFromMedinaStation
{
	public class Drawings
	{
		readonly static private string playerToken = "X";// "\u2573";
		readonly static private string dLH = "\u2550";
		readonly static private string dLV = "\u2551";
		readonly static private string lineHV = "\u256C";
		readonly static private string dLDR = "\u2554";
		readonly static private string dLDL = "\u2557";
		readonly static private string dLDH = "\u2566";
		readonly static private string dLUR = "\u255A";
		readonly static private string dLUL = "\u255D";
		readonly static private string dLUH = "\u2569";
		readonly static private string dLVR = "\u2560";
		readonly static private string dLVL = "\u2563";
		readonly static private string lightShade = "\u2591";
		readonly static private string mediumShade = "\u2592";
		readonly static private string darkShade = "\u2593";
		readonly static private string lineH = "\u2500";
		readonly static private string lineV = "\u2502";
		readonly static private string lADR = "\u256D";
		readonly static private string lADL = "\u256E";
		readonly static private string lAUL = "\u256F";
		readonly static private string lAUR = "\u2570";
		readonly static byte maxLineLength = 50;

		static private string GetStrSequence(string str, int count)
		{
			string line = "";

			while (line.Length < count)
				line += str;

			return line;
		}

		static public int DrawAnswerButtons (Stack<Answer> answers, bool back)
		{
			Console.WriteLine("\n");

			string line = "";
			foreach (Answer i in answers)
			{
				if (i.IsVisible())
					line += "[" + i.GetKeyword() + "] ";
			}

			if (back)
				line += "[back]";

			DrawCenterText(line + "\n");

			return (Console.WindowWidth - line.Length) / 2;
		}

		static private string GetTopLine(string title = null, int length = 0)
		{
			if (length == 0)
				length = maxLineLength;

			string line = dLDR;

			if (title != null)
				line += dLH + " " + title + " ";

			line += GetStrSequence(dLH, (length - 1 - line.Length)) + dLDL + "\n";

			return line;
		}
		static private string GetBottomLine (int length = 0)
		{
			if (length == 0)
				length = maxLineLength;

			//Bottom line
			string line = dLUR + GetStrSequence (dLH, length -2) + dLUL;

			return line;
		}

		static private string GetTextLine (string text)
		{
			string line = dLV + " "  + text;

			while (line.Length < maxLineLength - 1)
				line += " ";

			line += dLV + "\n";

			return line;
		}
		static public void GetMenuDrawing ()
		{
			//Title line
			string drawing = GetTopLine("Menu");
			drawing += GetTextLine ("You are a technician on a space station.");
			drawing += GetTextLine ("It was an easy job until one day");
			drawing += GetTextLine ("disaster struck! An asteroid hit the");
			drawing += GetTextLine("station! Are you able to escape?");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetPicture ()
		{
			string drawing = GetTopLine("Graduation photo");
			drawing +=		 (dLV + GetStrSequence(" ", 23) + "/\\" + GetStrSequence(" ", 23) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLDR + GetStrSequence (dLH, 22) + dLDL + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + "      O     O    O    " + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + "     ~|~   ~|~  ~|~   " + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + "     | |   | |  | |   " + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLUR + GetStrSequence(dLH, 22) + dLUL + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 48) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetBedroom()
		{
			string drawing = GetTopLine("Bedroom");
			drawing +=		 (dLV + GetStrSequence (" ", 12) + dLDR + GetStrSequence(dLH, 8) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence(dLH, 8) + dLDL + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 17) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 6) + playerToken + GetStrSequence(" ", 10) + GetStrSequence(mediumShade, 5) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 17) + GetStrSequence(mediumShade, 5) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 17) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence (" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence (" ", 12) + dLUR + GetStrSequence (dLH, 22) + dLUL + GetStrSequence (" ", 12) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine (drawing);
		}

		static public void GetFirstHallway()
		{
			string drawing = GetTopLine("Hallway");
			drawing += (dLV + GetStrSequence(" ", 48) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 40) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence (lightShade, 12) + GetStrSequence(" ", 22) + GetStrSequence(darkShade, 4) + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence (lightShade, 12) + GetStrSequence (" ", 7) + playerToken + GetStrSequence(" ", 15) + GetStrSequence(darkShade, 2) + GetStrSequence(" ", 7) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence (lightShade, 12) + GetStrSequence(" ", 15) + GetStrSequence (darkShade, 2) + GetStrSequence(" ", 15) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence (lightShade, 12) + GetStrSequence(" ", 14) + GetStrSequence(darkShade, 4) + GetStrSequence(" ", 14) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 17) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 17) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 48) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetDmgHallway()
		{
			string drawing = GetTopLine("Damaged Hallway");
			drawing += (dLV + GetStrSequence(" ", 48) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 17) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 17) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 14) + GetStrSequence(darkShade, 4) + GetStrSequence(" ", 20) + GetStrSequence(darkShade, 4) + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 15) + GetStrSequence(darkShade, 2) + GetStrSequence(" ", 6) + playerToken + GetStrSequence(" ", 15) + GetStrSequence(darkShade, 2) + GetStrSequence(" ", 7) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 31) + GetStrSequence(darkShade, 2) + GetStrSequence(" ", 15) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 30) + GetStrSequence(darkShade, 4) + GetStrSequence(" ", 14) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 40) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 48) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetWaterHallway()
		{
			string drawing = GetTopLine("Water Hallway");
			drawing += (dLV + GetStrSequence(" ", 48) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 40) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 22) + GetStrSequence (lightShade, 22) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 17) + playerToken + GetStrSequence(" ", 4) + GetStrSequence(lightShade, 6) + GetStrSequence(darkShade, 3) + GetStrSequence(lightShade, 13) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 22) + GetStrSequence(lightShade, 14) + GetStrSequence(darkShade, 3) + GetStrSequence (lightShade, 5) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 22) + lightShade + GetStrSequence(darkShade, 3) + GetStrSequence (lightShade, 18) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + GetStrSequence(dLH, 40) + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 48) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetDarkHallway()
		{
			string drawing = GetTopLine("Dark Hallway");
			drawing += (dLV + GetStrSequence(" ", 48) + dLV + "\n"
			+ dLV + " " + GetStrSequence(lightShade, 46) + " " + dLV + "\n"
			+ dLV + " " + GetStrSequence(lightShade, 46)+ " " + dLV + "\n"
			+ dLV + " " + GetStrSequence(lightShade, 46)+ " " + dLV + "\n"
			+ dLV + " " + GetStrSequence(lightShade, 46)+ " " + dLV + "\n"
			+ dLV + " " + GetStrSequence(lightShade, 46)+ " " + dLV + "\n"
			+ dLV + GetStrSequence(" ", 48) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetControlRoom()
		{
			string drawing = GetTopLine("Control room");
			drawing += (dLV + GetStrSequence(" ", 4) + dLDR + GetStrSequence(dLH, 16) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 16) + dLDL + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLV + GetStrSequence(" ", 38) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUH + GetStrSequence(" ", 38) + dLUH + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 24) + playerToken + GetStrSequence(" ", 23) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 48) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLDH + GetStrSequence(" ", 5) + dLDR + dLDL + GetStrSequence(" ", 7) + dLDR + dLDL + GetStrSequence(" ", 7) + dLDR + dLDL + GetStrSequence(" ", 7) + dLDR + dLDL + GetStrSequence(" ", 4) + dLDH + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLV + GetStrSequence(" ", 3) + GetStrSequence (darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence (" ", 2) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUR + GetStrSequence(dLH, 38) + dLUL + GetStrSequence(" ", 4) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetCommonRoom()
		{
			string drawing = GetTopLine("Common room");
			drawing += (dLV + GetStrSequence(" ", 4) + dLDR + GetStrSequence(dLH, 38) + dLDL + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLV + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 2) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUH + GetStrSequence(" ", 38) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 24) + playerToken + GetStrSequence(" ", 18) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 43) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLDH + GetStrSequence(" ", 38) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLV + GetStrSequence(" ", 38) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUR + GetStrSequence (dLH, 2) + dLVL + GetStrSequence(lineH, 4) + dLVR + GetStrSequence(dLH, 3) + dLVL + GetStrSequence(lineH, 4) + dLVR + GetStrSequence(dLH, 4) + dLVL + lADR + GetStrSequence(lineH, 2) + lADL + dLVR + GetStrSequence(dLH, 3) + dLVL + GetStrSequence(lineH, 4) + dLVR + GetStrSequence(dLH, 2) + dLUL + GetStrSequence(" ", 4) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetMaintenance()
		{
			string drawing = GetTopLine("Maintenance");
			drawing += (dLV + GetStrSequence(" ", 6) + dLDR + GetStrSequence(dLH, 14) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 14) + dLDL + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + dLV + GetStrSequence(" ", 26) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 2) + dLV + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + lineH + GetStrSequence(" ", 34) + lineH + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + lineV + GetStrSequence(" ", 34) + lineV + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + lineV + GetStrSequence(" ", 17) + playerToken + GetStrSequence(" ", 16) + lineV + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + lineH + GetStrSequence(" ", 34) + lineH + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + dLV + GetStrSequence (" ", 34) + dLV + GetStrSequence(" ", 6) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 6) + dLUR + GetStrSequence(dLH, 14) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 14) + dLUL + GetStrSequence(" ", 6) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetMRoom()
		{
			string drawing = GetTopLine("Administration office");
			drawing += (dLV + GetStrSequence(" ", 4) + dLDR + GetStrSequence(dLH, 16) + lineV + GetStrSequence(lineH, 4) + lineV + GetStrSequence(dLH, 16) + dLDL + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUH + GetStrSequence(" ", 38) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + lADL + GetStrSequence(" ", 38) + dLUH + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + lineV + GetStrSequence (" ", 19) + playerToken + GetStrSequence(" ", 23) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + lineV + GetStrSequence(" ", 2) + "[Body]" + GetStrSequence(" ", 35) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + lAUL + GetStrSequence(" ", 14) + dLDR + dLDL + GetStrSequence(" ", 7) + dLDR + dLDL + GetStrSequence(" ", 13) + dLDH + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLDH + GetStrSequence(" ", 9) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(darkShade, 6) + GetStrSequence(" ", 3) + GetStrSequence(" ", 8) + dLV + GetStrSequence(" ", 4) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 4) + dLUR + GetStrSequence(dLH, 38) + dLUL + GetStrSequence(" ", 4) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetDeadDrawing()
		{
			string drawing = GetTopLine();
			drawing +=		 (dLV + "           ##      ##     ##      ##            " + dLV + "\n"
								+ dLV + "             ##  ##         ##  ##              " + dLV + "\n"
								+ dLV + "               ##             ##                " + dLV + "\n"
								+ dLV + "             ##  ##         ##  ##              " + dLV + "\n"
								+ dLV + "           ##      ##     ##      ##            " + dLV + "\n"
								+ dLV + "                                                " + dLV + "\n"
								+ dLV + "                ###############                 " + dLV + "\n"
								+ dLV + "                                                " + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetBlockedDrawing()
		{
			string drawing = GetTopLine();
			drawing +=		 (dLV + "             ###               ###              " + dLV + "\n"
								+ dLV + "                ###         ###                 " + dLV + "\n"
								+ dLV + "                   ###   ###                    " + dLV + "\n"
								+ dLV + "                      ###                       " + dLV + "\n"
								+ dLV + "                      ###                       " + dLV + "\n"
								+ dLV + "                   ###   ###                    " + dLV + "\n"
								+ dLV + "                ###         ###                 " + dLV + "\n"
								+ dLV + "             ###               ###              " + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetIDCard()
		{
			string drawing = GetTopLine("ID-Card");
			drawing +=		 (dLV + "                                                " + dLV + "\n"
								+ dLV + "          ############################          " + dLV + "\n"
								+ dLV + "          # Mr. Black                #          " + dLV + "\n"
								+ dLV + "          #--------------------------#          " + dLV + "\n"
								+ dLV + "          #                          #          " + dLV + "\n"
								+ dLV + "          # ID: XXXX-XXXX-XXXX-94    #          " + dLV + "\n"
								+ dLV + "          ############################          " + dLV + "\n"
								+ dLV + "                                                " + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}

		static public void GetComputer()
		{
			string drawing = GetTopLine("Computer");
			drawing +=		 (dLV + GetStrSequence(" ", 12 ) + dLDR + GetStrSequence(dLH, 22 ) + dLDL + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12 ) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12 ) + dLV + GetStrSequence(" ", 22)  + dLV + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12 ) + dLV + "   [CRITICAL ERROR]   "+ dLV + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12 ) + dLV + GetStrSequence(" ", 22 ) + dLV + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12) + dLV + GetStrSequence(" ", 22) + dLV + GetStrSequence(" ", 12) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 12 ) + dLUR + GetStrSequence(dLH, 9) + dLDH + GetStrSequence(dLH, 2) + dLDH + GetStrSequence(dLH, 9) + dLUL + GetStrSequence(" ", 12 ) + dLV + "\n"
								+ dLV + GetStrSequence(" ", 10) + dLDR + GetStrSequence (dLH, 11) + dLUH + GetStrSequence(dLH, 2) + dLUH + GetStrSequence(dLH, 11) + dLDL + GetStrSequence(" ", 10) + dLV + "\n");
			drawing += GetBottomLine();
			DrawCenterTextLine(drawing);
		}
		static public void GetEscapePod()
		{
			string drawing = GetTopLine("Escape pod");
			drawing += dLV + GetStrSequence(" ", 18) + dLDR + dLH + dLDH + GetStrSequence(dLH, 6) + dLDH + dLH + dLDL + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + " " + dLV + GetStrSequence(lightShade, 6) + dLV + " " + dLV + GetStrSequence(" ", 18) + dLV+ "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + " " + dLV + GetStrSequence(" ", 6) + dLV + " " + dLV + GetStrSequence(" ", 18) + dLV+ "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + " " + dLV + GetStrSequence(" ", 6) + dLV + " " + dLV + GetStrSequence(" ", 18) + dLV+ "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + " " + dLV + "[PULL]" + dLV + " " + dLV + GetStrSequence(" ", 18) + dLV+ "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + " " + dLUR + GetStrSequence(dLH, 6) + dLUL + " " + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLUR + GetStrSequence(dLH, 10) + dLUL + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += GetBottomLine();

			DrawCenterTextLine(drawing);
		}

		static public void GetFood()
		{
			string drawing = GetTopLine("Food");
			drawing += dLV + GetStrSequence(" ", 48) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9) + dLDR + GetStrSequence (dLH, 7)     + dLDL + GetStrSequence (" ", 2) + dLDR + GetStrSequence(dLH, 7)      + dLDL + GetStrSequence (" ", 2) + dLDR + GetStrSequence(dLH, 7) + dLDL + GetStrSequence(" ",8) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9) + dLV + GetStrSequence (" ", 7)      + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence (" ", 7)      + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence (" ", 7)      + dLV + GetStrSequence(" ", 8) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9) + dLV + GetStrSequence (darkShade, 7)+ dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence (darkShade, 7)+ dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence (darkShade, 7)+ dLV +  GetStrSequence(" ", 8) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9) + dLV + GetStrSequence(darkShade, 7) + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence(darkShade, 7) + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence(darkShade, 7) + dLV + GetStrSequence(" ", 8) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9) + dLV + GetStrSequence(" ", 7)       + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence(" ", 7)       + dLV  + GetStrSequence (" ", 2) + dLV + GetStrSequence(" ", 7)       + dLV + GetStrSequence(" ", 8) + dLV + "\n";
			drawing += dLV + GetStrSequence (" ", 9)  + dLUR + GetStrSequence(dLH, 7)      + dLUL + GetStrSequence (" ", 2) + dLUR + GetStrSequence(dLH, 7)      + dLUL + GetStrSequence (" ", 2) + dLUR + GetStrSequence(dLH, 7)      + dLUL + GetStrSequence(" ", 8) + dLV + "\n";
			drawing += GetBottomLine();

			DrawCenterTextLine(drawing);
		}

		static public void DrawWinScreen()
		{
			string drawing = GetTopLine();
			drawing += dLV + GetStrSequence(" ", 48) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 48) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 10) + "██        ██  ██  ███    ██" + GetStrSequence(" ", 11) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 10) + "██   ██   ██  ██  ██ ██  ██" + GetStrSequence(" ", 11) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 10) + "██ ██  ██ ██  ██  ██  ██ ██" + GetStrSequence(" ", 11) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 10) + "███      ███  ██  ██    ███" + GetStrSequence(" ", 11) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 48) + dLV + "\n";
			drawing += GetBottomLine();

			DrawCenterTextLine(drawing);
		}

		static public void DrawVendingMachine ()
		{
			string drawing = GetTopLine("Old vending machine");
			drawing += dLV + GetStrSequence(" ", 18) + dLDR + GetStrSequence(dLH, 10) + dLDL + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + GetStrSequence(" ", 10) + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + lightShade + lightShade + darkShade + GetStrSequence(lightShade, 5) + darkShade + lightShade + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + GetStrSequence("¯", 10) + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + darkShade + GetStrSequence (lightShade, 2) + darkShade + lightShade + darkShade + lightShade + darkShade+ lightShade + lightShade + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLV + GetStrSequence("¯", 10) + dLV + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += dLV + GetStrSequence(" ", 18) + dLUR + GetStrSequence(dLH, 10) + dLUL + GetStrSequence(" ", 18) + dLV + "\n";
			drawing += GetBottomLine();

			DrawCenterTextLine(drawing);
		}

		static public void DrawLoadingScreen()
		{
			DrawCenterText ("                                              *####*  \n");
			DrawCenterText ("                                           *##     ##*\n");
			DrawCenterText ("                                           *##     ##*\n");
			DrawCenterText ("                                             *####*   \n");
			DrawCenterText ("                                          *###*       \n");
			DrawCenterText ("                  *** ### ### ***       *###*         \n");
			DrawCenterText ("              *##                 ##* *###*           \n");
			DrawCenterText ("          *##                         ####*           \n");
			DrawCenterText ("       *##                               ##*          \n");
			DrawCenterText ("     *##            *## ### ##*            ##*        \n");
			DrawCenterText ("   *##          ##*             *##          ##*      \n");
			DrawCenterText ("  *##        ##*                   *##        ##*     \n");
			DrawCenterText (" *##       ##*                       *##       ##*    \n");
			DrawCenterText ("*##       ##*                         *##       ##*   \n");
			DrawCenterText ("*##      ##*           *###*           *##      ##*   \n");
			DrawCenterText ("*##      ##*          #######          *##      ##*   \n");
			DrawCenterText ("*##      ##*           *###*           *##      ##*   \n");
			DrawCenterText ("*##       ##*                         *##       ##*   \n");
			DrawCenterText (" *##       ##*                       *##       ##*    \n");
			DrawCenterText ("  *##        ##*                   *##        ##*     \n");
			DrawCenterText ("   *##          ##*             *##          ##*      \n");
			DrawCenterText ("     *##            *## ### *##            ##*        \n");
			DrawCenterText ("       *#                                ##*          \n");
			DrawCenterText ("          *##                         ##*             \n");
			DrawCenterText ("              *##                 ##*                 \n");
			DrawCenterText("                  *** ### ### ***                     \n");

			Console.WriteLine();
			Console.WriteLine();

			DrawCenterText("•••• <<<< Welcome to Medina station>>>> ••••", 30);
			
			Console.WriteLine();
			Console.WriteLine();

			for (int i = 0; i <= 100; ++i)
			{
				string loadingText = "<<<< Loading " + i.ToString() + "% >>>>";
				DrawCenterText(loadingText);
				System.Threading.Thread.Sleep(8);
			}

			DrawCenterText("<<<< Complete! >>>>");
			Console.WriteLine("\n\n\n");
		}

		static public void SetCursorPositionForText (string text)
		{
			int cPos = Math.Max(0, (Console.WindowWidth - text.Length) / 2);
			Console.SetCursorPosition(cPos, Console.CursorTop);
		}

		static public void DrawCenterText(string text)
		{
			SetCursorPositionForText(text);
			Console.Write(text);
		}

		static public void DrawCenterTextLine(string text)
		{
			string[] lines = text.Split('\n');

			foreach (string i in lines)
			{
				SetCursorPositionForText(i);
				Console.WriteLine(i);
			}
		}
		static public void DrawCenterText(string text, int delayMs)
		{
			SetCursorPositionForText(text);

			foreach (char c in text)
			{
				Console.Write(c);
				System.Threading.Thread.Sleep(delayMs);
			}
		}
	}

}
