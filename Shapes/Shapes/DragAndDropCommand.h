#pragma once
#include "ICommand.h"

class Toolbar;

class DragAndDropCommand : public ICommand
{
public:
	DragAndDropCommand(Toolbar* toolBar)
		: m_toolBar(toolBar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolBar;
};

