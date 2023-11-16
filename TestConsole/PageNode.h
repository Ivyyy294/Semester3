#pragma once
#include <string>
#include <vector>
#include <memory>

class PageNode
{
public:
	typedef std::shared_ptr <PageNode> Ptr;
	typedef std::vector <PageNode::Ptr> Vec;

	//Set
	inline void SetActionEvent (const std::string _actionEvent) { actionEvent = _actionEvent; };
	inline void SetDrawing (const std::wstring& _drawing) { drawing = _drawing; }
	inline void SetText (const std::wstring& _text) { text = _text; }
	inline void SetHistorie (bool val) { historie = val; }

	//Get
	inline const std::string& GetActionEvent () const { return actionEvent; }
	inline const std::wstring& GetDrawing () const { return drawing; }
	inline const std::wstring GetText () const { return text; }
	inline bool IsGoBackPossible () const { return goBackPossible; }

private:
	std::wstring drawing;
	std::wstring text;
	std::string actionEvent;
	bool goBackPossible{ true };
	bool historie{ true };
};

