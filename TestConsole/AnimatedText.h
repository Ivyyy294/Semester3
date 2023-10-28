#pragma once
#include <string>

class AnimatedText
{
public:
	void Update ();
	void SetText (const std::wstring& _text, int _speedMs);
	std::wstring GetCurrentText () const;
	bool Done () const;

private:
	std::wstring text;
	float timer;
	int speedMs;

	int GetCurrentCharCount () const;
};

