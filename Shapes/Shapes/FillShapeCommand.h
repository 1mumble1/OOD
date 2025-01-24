#pragma once
#include "ICommand.h"

class Toolbar;

class FillShapeCommand : public ICommand
{
public:
	FillShapeCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};

