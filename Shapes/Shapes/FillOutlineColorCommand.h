#pragma once
#include "ICommand.h"

class Toolbar;

class FillOutlineColorCommand : public ICommand
{
public:
	FillOutlineColorCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{
	}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

