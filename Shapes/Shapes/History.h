#pragma once
#include "stdafx.h"
#include "ShapeMemento.h"

class History
{
public:
	void UpdateHistory(std::shared_ptr<ShapeMemento> state);
	std::shared_ptr<ShapeMemento> Undo();

private:
	std::stack<std::shared_ptr<ShapeMemento>> m_history;
};