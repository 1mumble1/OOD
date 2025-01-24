#pragma once
#include "ICommand.h"

class Toolbar;

class CreateRectangleCommand : public ICommand
{
public:
	CreateRectangleCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};
