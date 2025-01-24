#pragma once
#include "ICommand.h"

class Toolbar;

class CreateTriangleCommand : public ICommand
{
public:
	CreateTriangleCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};

