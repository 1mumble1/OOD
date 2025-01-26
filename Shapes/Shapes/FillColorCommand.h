#pragma once
#include "ICommand.h"

class Toolbar;

class FillColorCommand : public ICommand
{
public:
	FillColorCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{
	}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

