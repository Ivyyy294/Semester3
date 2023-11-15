#pragma once
#include <string>
#include <vector>
#include "PageEdge.h"

class PageNode
{
public:
	typedef std::vector <PageNode> Vec;

	//Set
	inline void SetActionEvent (const std::string _actionEvent) { actionEvent = _actionEvent; };
	inline void SetDrawing (const std::wstring& _drawing) { drawing = _drawing; }
	inline void SetText (const std::wstring& _text) { text = _text; }
	inline void AddEdge (const PageEdge& edge);

	//Get
	inline const PageEdge::Vec& GetEdges () const { return edges; }
	inline const std::wstring& GetDrawing () const { return drawing; }
	inline const std::wstring GetText () const { return text; }
	inline bool IsGoBackPossible () const { return goBackPossible; }

private:
	std::wstring drawing;
	std::wstring text;
	std::string actionEvent;
	bool goBackPossible{ true };

	PageEdge::Vec edges;
};

