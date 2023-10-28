#include "Drawings.h"

const int maxLineLength{ 50 };
const std::wstring playerToken = L"X";// "\u2573";
const std::wstring dLH = L"\u2550";
const std::wstring dLV = L"\u2551";
const std::wstring lineHV = L"\u256C";
const std::wstring dLDR = L"\u2554";
const std::wstring dLDL = L"\u2557";
const std::wstring dLDH = L"\u2566";
const std::wstring dLUR = L"\u255A";
const std::wstring dLUL = L"\u255D";
const std::wstring dLUH = L"\u2569";
const std::wstring dLVR = L"\u2560";
const std::wstring dLVL = L"\u2563";
const std::wstring lightShade = L"\u2591";
const std::wstring mediumShade = L"\u2592";
const std::wstring darkShade = L"\u2593";
const std::wstring lineH = L"\u2500";
const std::wstring lineV = L"\u2502";
const std::wstring lADR = L"\u256D";
const std::wstring lADL = L"\u256E";
const std::wstring lAUL = L"\u256F";
const std::wstring lAUR = L"\u2570";
const std::wstring lineBreak = L"\n";
const std::wstring space = L" ";

std::wstring Drawings::LoadingScreen ()
{
		return(L"                                              *####*  \n"
				 "                                           *##     ##*\n"
				 "                                           *##     ##*\n"
				 "                                             *####*   \n"
				 "                                          *###*       \n"
				 "                  *** ### ### ***       *###*         \n"
				 "              *##                 ##* *###*           \n"
				 "          *##                         ####*           \n"
				 "       *##                               ##*          \n"
				 "     *##            *## ### ##*            ##*        \n"
				 "   *##          ##*             *##          ##*      \n"
				 "  *##        ##*                   *##        ##*     \n"
				 " *##       ##*                       *##       ##*    \n"
				 "*##       ##*                         *##       ##*   \n"
				 "*##      ##*           *###*           *##      ##*   \n"
				 "*##      ##*          #######          *##      ##*   \n"
				 "*##      ##*           *###*           *##      ##*   \n"
				 "*##       ##*                         *##       ##*   \n"
				 " *##       ##*                       *##       ##*    \n"
				 "  *##        ##*                   *##        ##*     \n"
				 "   *##          ##*             *##          ##*      \n"
				 "     *##            *## ### *##            ##*        \n"
				 "       *#                                ##*          \n"
				 "          *##                         ##*             \n"
				 "              *##                 ##*                 \n"
				 "                  *** ### ### ***                     \n");
}

std::wstring Drawings::Menu ()
{
	std::wstring drawing = GetTopLine (L"Menu");
	drawing += GetTextLine (L"");
	drawing += GetTextLine (L"You are a technician on a space station.");
	drawing += GetTextLine (L"It was an easy job until one day");
	drawing += GetTextLine (L"disaster struck! An asteroid hit the");
	drawing += GetTextLine (L"station! Are you able to escape?");
	drawing += GetTextLine (L"");
	drawing += GetTextLine (L"");
	drawing += GetTextLine (L"");
	drawing += GetBottomLine ();

	return drawing;
}

std::wstring Drawings::GetPicture ()
{
	std::wstring drawing = GetTopLine (L"Graduation photo");
	drawing += (dLV + GetStrSequence (space, 23) + L"/\\" + GetStrSequence (space, 23) + dLV + L"\n"
		+ dLV + GetStrSequence (space, 12) + dLDR + GetStrSequence (dLH, 22) + dLDL + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + L"      O     O    O    " + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + L"     ~|~   ~|~  ~|~   " + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + L"     | |   | |  | |   " + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLUR + GetStrSequence (dLH, 22) + dLUL + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetBedroom ()
{
	std::wstring drawing = GetTopLine (L"Bedroom");
	drawing += (dLV + GetStrSequence (space, 12) + dLDR + GetStrSequence (dLH, 8) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 8) + dLDL + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 17) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 6) + playerToken + GetStrSequence (space, 10) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 17) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 17) + GetStrSequence (mediumShade, 5) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLUR + GetStrSequence (dLH, 22) + dLUL + GetStrSequence (space, 12) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetFirstHallway ()
{
	std::wstring drawing = GetTopLine (L"Hallway");
	drawing += (dLV + GetStrSequence (space, 48) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 40) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (lightShade, 12) + GetStrSequence (space, 22) + GetStrSequence (darkShade, 4) + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (lightShade, 12) + GetStrSequence (space, 7) + playerToken + GetStrSequence (space, 15) + GetStrSequence (darkShade, 2) + GetStrSequence (space, 7) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (lightShade, 12) + GetStrSequence (space, 15) + GetStrSequence (darkShade, 2) + GetStrSequence (space, 15) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (lightShade, 12) + GetStrSequence (space, 14) + GetStrSequence (darkShade, 4) + GetStrSequence (space, 14) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 17) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 17) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetDmgHallway ()
{
	std::wstring drawing = GetTopLine (L"Damaged Hallway");
	drawing += (dLV + GetStrSequence (space, 48) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 17) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 17) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 14) + GetStrSequence (darkShade, 4) + GetStrSequence (space, 20) + GetStrSequence (darkShade, 4) + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 15) + GetStrSequence (darkShade, 2) + GetStrSequence (space, 6) + playerToken + GetStrSequence (space, 15) + GetStrSequence (darkShade, 2) + GetStrSequence (space, 7) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 31) + GetStrSequence (darkShade, 2) + GetStrSequence (space, 15) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 30) + GetStrSequence (darkShade, 4) + GetStrSequence (space, 14) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 40) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetWaterHallway ()
{
	std::wstring drawing = GetTopLine (L"Water Hallway");
	drawing += (dLV + GetStrSequence (space, 48) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 40) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 22) + GetStrSequence (lightShade, 22) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 17) + playerToken + GetStrSequence (space, 4) + GetStrSequence (lightShade, 6) + GetStrSequence (darkShade, 3) + GetStrSequence (lightShade, 13) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 22) + GetStrSequence (lightShade, 14) + GetStrSequence (darkShade, 3) + GetStrSequence (lightShade, 5) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 22) + lightShade + GetStrSequence (darkShade, 3) + GetStrSequence (lightShade, 18) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + GetStrSequence (dLH, 40) + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetDarkHallway ()
{
	std::wstring drawing = GetTopLine (L"Dark Hallway");
	drawing += (dLV + GetStrSequence (space, 48) + dLV + lineBreak
		+ dLV + space + GetStrSequence (lightShade, 46) + space + dLV + lineBreak
		+ dLV + space + GetStrSequence (lightShade, 46) + space + dLV + lineBreak
		+ dLV + space + GetStrSequence (lightShade, 46) + space + dLV + lineBreak
		+ dLV + space + GetStrSequence (lightShade, 46) + space + dLV + lineBreak
		+ dLV + space + GetStrSequence (lightShade, 46) + space + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetControlRoom ()
{
	std::wstring drawing = GetTopLine (L"Control room");
	drawing += (dLV + GetStrSequence (space, 4) + dLDR + GetStrSequence (dLH, 16) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 16) + dLDL + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLV + GetStrSequence (space, 38) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUH + GetStrSequence (space, 38) + dLUH + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 24) + playerToken + GetStrSequence (space, 23) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 48) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLDH + GetStrSequence (space, 5) + dLDR + dLDL + GetStrSequence (space, 7) + dLDR + dLDL + GetStrSequence (space, 7) + dLDR + dLDL + GetStrSequence (space, 7) + dLDR + dLDL + GetStrSequence (space, 4) + dLDH + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLV + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUR + GetStrSequence (dLH, 38) + dLUL + GetStrSequence (space, 4) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetCommonRoom ()
{
	std::wstring drawing = GetTopLine (L"Common room");
	drawing += (dLV + GetStrSequence (space, 4) + dLDR + GetStrSequence (dLH, 38) + dLDL + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLV + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUH + GetStrSequence (space, 38) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 24) + playerToken + GetStrSequence (space, 18) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 43) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLDH + GetStrSequence (space, 38) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLV + GetStrSequence (space, 38) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUR + GetStrSequence (dLH, 2) + dLVL + GetStrSequence (lineH, 4) + dLVR + GetStrSequence (dLH, 3) + dLVL + GetStrSequence (lineH, 4) + dLVR + GetStrSequence (dLH, 4) + dLVL + lADR + GetStrSequence (lineH, 2) + lADL + dLVR + GetStrSequence (dLH, 3) + dLVL + GetStrSequence (lineH, 4) + dLVR + GetStrSequence (dLH, 2) + dLUL + GetStrSequence (space, 4) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetMaintenance ()
{
	std::wstring drawing = GetTopLine (L"Maintenance");
	drawing += (dLV + GetStrSequence (space, 6) + dLDR + GetStrSequence (dLH, 14) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 14) + dLDL + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + dLV + GetStrSequence (space, 26) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + lineH + GetStrSequence (space, 34) + lineH + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + lineV + GetStrSequence (space, 34) + lineV + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + lineV + GetStrSequence (space, 17) + playerToken + GetStrSequence (space, 16) + lineV + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + lineH + GetStrSequence (space, 34) + lineH + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + dLV + GetStrSequence (space, 34) + dLV + GetStrSequence (space, 6) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 6) + dLUR + GetStrSequence (dLH, 14) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 14) + dLUL + GetStrSequence (space, 6) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetMRoom ()
{
	std::wstring drawing = GetTopLine (L"Administration office");
	drawing += (dLV + GetStrSequence (space, 4) + dLDR + GetStrSequence (dLH, 16) + lineV + GetStrSequence (lineH, 4) + lineV + GetStrSequence (dLH, 16) + dLDL + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUH + GetStrSequence (space, 38) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + lADL + GetStrSequence (space, 38) + dLUH + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + lineV + GetStrSequence (space, 19) + playerToken + GetStrSequence (space, 23) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + lineV + GetStrSequence (space, 2) + L"[Body]" + GetStrSequence (space, 35) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + lAUL + GetStrSequence (space, 14) + dLDR + dLDL + GetStrSequence (space, 7) + dLDR + dLDL + GetStrSequence (space, 13) + dLDH + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLDH + GetStrSequence (space, 9) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (darkShade, 6) + GetStrSequence (space, 3) + GetStrSequence (space, 8) + dLV + GetStrSequence (space, 4) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 4) + dLUR + GetStrSequence (dLH, 38) + dLUL + GetStrSequence (space, 4) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetDeadDrawing ()
{
	std::wstring drawing = GetTopLine (L"");
	drawing += (dLV + L"           ##      ##     ##      ##            " + dLV + lineBreak
		+ dLV + L"             ##  ##         ##  ##              " + dLV + lineBreak
		+ dLV + L"               ##             ##                " + dLV + lineBreak
		+ dLV + L"             ##  ##         ##  ##              " + dLV + lineBreak
		+ dLV + L"           ##      ##     ##      ##            " + dLV + lineBreak
		+ dLV + L"                                                " + dLV + lineBreak
		+ dLV + L"                ###############                 " + dLV + lineBreak
		+ dLV + L"                                                " + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetBlockedDrawing ()
{
	std::wstring drawing = GetTopLine (L"");
	drawing += (dLV + L"             ###               ###              " + dLV + lineBreak
		+ dLV + L"                ###         ###                 " + dLV + lineBreak
		+ dLV + L"                   ###   ###                    " + dLV + lineBreak
		+ dLV + L"                      ###                       " + dLV + lineBreak
		+ dLV + L"                      ###                       " + dLV + lineBreak
		+ dLV + L"                   ###   ###                    " + dLV + lineBreak
		+ dLV + L"                ###         ###                 " + dLV + lineBreak
		+ dLV + L"             ###               ###              " + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetIDCard ()
{
	std::wstring drawing = GetTopLine (L"ID-Card");
	drawing += (dLV + L"                                                " + dLV + lineBreak
		+ dLV + L"          ############################          " + dLV + lineBreak
		+ dLV + L"          # Mr. Black                #          " + dLV + lineBreak
		+ dLV + L"          #--------------------------#          " + dLV + lineBreak
		+ dLV + L"          #                          #          " + dLV + lineBreak
		+ dLV + L"          # ID: XXXX-XXXX-XXXX-94    #          " + dLV + lineBreak
		+ dLV + L"          ############################          " + dLV + lineBreak
		+ dLV + L"                                                " + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}

std::wstring Drawings::GetComputer ()
{
	std::wstring drawing = GetTopLine (L"Computer");
	drawing += (dLV + GetStrSequence (space, 12) + dLDR + GetStrSequence (dLH, 22) + dLDL + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + L"   [CRITICAL ERROR]   " + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLV + GetStrSequence (space, 22) + dLV + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 12) + dLUR + GetStrSequence (dLH, 9) + dLDH + GetStrSequence (dLH, 2) + dLDH + GetStrSequence (dLH, 9) + dLUL + GetStrSequence (space, 12) + dLV + lineBreak
		+ dLV + GetStrSequence (space, 10) + dLDR + GetStrSequence (dLH, 11) + dLUH + GetStrSequence (dLH, 2) + dLUH + GetStrSequence (dLH, 11) + dLDL + GetStrSequence (space, 10) + dLV + lineBreak);
	drawing += GetBottomLine ();
	return drawing;
}
std::wstring Drawings::GetEscapePod ()
{
	std::wstring drawing = GetTopLine (L"Escape pod");
	drawing += dLV + GetStrSequence (space, 18) + dLDR + dLH + dLDH + GetStrSequence (dLH, 6) + dLDH + dLH + dLDL + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + space + dLV + GetStrSequence (lightShade, 6) + dLV + space + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + space + dLV + GetStrSequence (space, 6) + dLV + space + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + space + dLV + GetStrSequence (space, 6) + dLV + space + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + space + dLV + L"[PULL]" + dLV + space + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + space + dLUR + GetStrSequence (dLH, 6) + dLUL + space + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLUR + GetStrSequence (dLH, 10) + dLUL + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += GetBottomLine ();

	return drawing;
}

std::wstring Drawings::GetFood ()
{
	std::wstring drawing = GetTopLine (L"Food");
	drawing += dLV + GetStrSequence (space, 48) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLDR + GetStrSequence (dLH, 7) + dLDL + GetStrSequence (space, 2) + dLDR + GetStrSequence (dLH, 7) + dLDL + GetStrSequence (space, 2) + dLDR + GetStrSequence (dLH, 7) + dLDL + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (darkShade, 7) + dLV + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 2) + dLV + GetStrSequence (space, 7) + dLV + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 9) + dLUR + GetStrSequence (dLH, 7) + dLUL + GetStrSequence (space, 2) + dLUR + GetStrSequence (dLH, 7) + dLUL + GetStrSequence (space, 2) + dLUR + GetStrSequence (dLH, 7) + dLUL + GetStrSequence (space, 8) + dLV + lineBreak;
	drawing += GetBottomLine ();

	return drawing;
}

std::wstring Drawings::DrawWinScreen ()
{
	std::wstring drawing = GetTopLine (L"");
	drawing += dLV + GetStrSequence (space, 48) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 48) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 10) + L"██        ██  ██  ███    ██" + GetStrSequence (space, 11) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 10) + L"██   ██   ██  ██  ██ ██  ██" + GetStrSequence (space, 11) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 10) + L"██ ██  ██ ██  ██  ██  ██ ██" + GetStrSequence (space, 11) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 10) + L"███      ███  ██  ██    ███" + GetStrSequence (space, 11) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 48) + dLV + lineBreak;
	drawing += GetBottomLine ();

	return drawing;
}

std::wstring Drawings::DrawVendingMachine ()
{
	std::wstring drawing = GetTopLine (L"Old vending machine");
	drawing += dLV + GetStrSequence (space, 18) + dLDR + GetStrSequence (dLH, 10) + dLDL + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + GetStrSequence (space, 10) + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + lightShade + lightShade + darkShade + GetStrSequence (lightShade, 5) + darkShade + lightShade + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + GetStrSequence (L"¯", 10) + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + darkShade + GetStrSequence (lightShade, 2) + darkShade + lightShade + darkShade + lightShade + darkShade + lightShade + lightShade + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLV + GetStrSequence (L"¯", 10) + dLV + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += dLV + GetStrSequence (space, 18) + dLUR + GetStrSequence (dLH, 10) + dLUL + GetStrSequence (space, 18) + dLV + lineBreak;
	drawing += GetBottomLine ();

	return drawing;
}

std::wstring Drawings::GetTopLine (const std::wstring& title, int length)
{
	if (length == 0)
		length = maxLineLength;

	std::wstring line = dLDR;

	line += dLH + space + title + space;

	line += GetStrSequence (dLH, (length - 1 - line.size())) + dLDL + lineBreak;

	return line;
}

std::wstring Drawings::GetStrSequence (const std::wstring& str, int count)
{
	std::wstring line = L"";

	while (line.size() < count)
		line += str;

	return line;
}

std::wstring Drawings::GetTextLine (const std::wstring& text)
{
	std::wstring line = dLV + space + text;

	while (line.size() < maxLineLength - 1)
		line += space;

	line += dLV + lineBreak;

	return line;
}

std::wstring Drawings::GetBottomLine (int length)
{
	if (length == 0)
		length = maxLineLength;

	//Bottom line
	std::wstring line = dLUR + GetStrSequence (dLH, length - 2) + dLUL;

	return line;
}
