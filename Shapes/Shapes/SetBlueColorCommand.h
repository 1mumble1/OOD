#pragma once
#include "ICommand.h"

class Toolbar;

class SetBlueColorCommand : public ICommand
{
public:
	SetBlueColorCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{
	}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

