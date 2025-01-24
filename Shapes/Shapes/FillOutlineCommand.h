#pragma once
#include "ICommand.h"

class Toolbar;

class FillOutlineCommand : public ICommand
{
public:
	FillOutlineCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};

