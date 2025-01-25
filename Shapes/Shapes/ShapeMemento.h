#pragma once
#include "stdafx.h"

class ShapeMemento
{
public:
	ShapeMemento(std::vector<IShapePtr> state)
		: m_state(state)
	{}

	std::vector<IShapePtr> GetState();

private:
	std::vector<IShapePtr> m_state;
};

