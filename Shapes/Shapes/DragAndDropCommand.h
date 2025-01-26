#pragma once
#include "ICommand.h"

class Toolbar;

class DragAndDropCommand : public ICommand
{
public:
	DragAndDropCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

