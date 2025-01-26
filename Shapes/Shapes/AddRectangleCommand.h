#pragma once
#include "ICommand.h"

class Toolbar;

class AddRectangleCommand : public ICommand
{
public:
	AddRectangleCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

