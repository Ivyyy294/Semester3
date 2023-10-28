#pragma once
#include <string>

class Drawings
{
public:
	static std::wstring LoadingScreen ();
	static std::wstring Menu ();

    std::wstring GetPicture ();

	 std::wstring GetBedroom ();

	 std::wstring GetFirstHallway ();

	 std::wstring GetDmgHallway ();

	 std::wstring GetWaterHallway ();

	 std::wstring GetDarkHallway ();

	 std::wstring GetControlRoom ();

	 std::wstring GetCommonRoom ();

	 std::wstring GetMaintenance ();

	 std::wstring GetMRoom ();

	 std::wstring GetDeadDrawing ();

	 std::wstring GetBlockedDrawing ();

	 std::wstring GetIDCard ();

	 std::wstring GetComputer ();

	 std::wstring GetEscapePod ();

	 std::wstring GetFood ();

	 std::wstring DrawWinScreen ();

	 std::wstring DrawVendingMachine ();

private:
	static std::wstring GetTopLine (const std::wstring& title, int length = 0);
	static std::wstring GetStrSequence (const std::wstring& str, int count);
	static std::wstring GetTextLine (const std::wstring& text);
	static std::wstring GetBottomLine (int length = 0);
};

