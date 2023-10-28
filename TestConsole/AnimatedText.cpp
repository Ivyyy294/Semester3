#include "AnimatedText.h"
#include "IvyyyTime.h"

void AnimatedText::Update ()
{
	timer += Ivyyy::Time::DeltaTime ();
}

void AnimatedText::SetText (const std::wstring& _text, int _speedMs)
{
	text = _text;
	speedMs = _speedMs;
	timer = 0.f;
}

std::wstring AnimatedText::GetCurrentText () const
{
	return text.substr (0, GetCurrentCharCount());
}

bool AnimatedText::Done () const
{
	return GetCurrentCharCount () == text.size ();
}

int AnimatedText::GetCurrentCharCount () const
{
	int charCount = std::min (text.size (), (size_t) std::abs ((timer * 1000.f) / (float)speedMs));
	return charCount;
}
