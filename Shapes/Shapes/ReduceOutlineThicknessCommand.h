#pragma once
#include "ICommand.h"

class Toolbar;

class ReduceOutlineThicknessCommand : public ICommand
{
public:
	ReduceOutlineThicknessCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

