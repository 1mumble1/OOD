#pragma once
#include "ICommand.h"

class Toolbar;

class AddCircleCommand : public ICommand
{
public:
	AddCircleCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

