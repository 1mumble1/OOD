#pragma once
#include "ICommand.h"

class Toolbar;

class CreateCircleCommand : public ICommand
{
public:
	CreateCircleCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};

