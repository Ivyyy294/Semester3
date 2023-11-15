#pragma once
#include <string>

class Drawings
{
public:
	static std::wstring LoadingScreen ();
	static std::wstring Menu ();
	static std::wstring GetPicture ();
	static std::wstring GetBedroom ();
	static std::wstring GetFirstHallway ();
	static std::wstring GetDmgHallway ();
	static std::wstring GetWaterHallway ();
	static std::wstring GetDarkHallway ();
	static std::wstring GetControlRoom ();
	static std::wstring GetCommonRoom ();
	static std::wstring GetMaintenance ();
	static std::wstring GetMRoom ();
	static std::wstring GetDeadDrawing ();
	static std::wstring GetBlockedDrawing ();
	static std::wstring GetIDCard ();
	static std::wstring GetComputer ();
	static std::wstring GetEscapePod ();
	static std::wstring GetFood ();
	static std::wstring DrawWinScreen ();
	static std::wstring DrawVendingMachine ();

private:
	static std::wstring GetTopLine (const std::wstring& title, int length = 0);
	static std::wstring GetStrSequence (const std::wstring& str, int count);
	static std::wstring GetTextLine (const std::wstring& text);
	static std::wstring GetBottomLine (int length = 0);
};

