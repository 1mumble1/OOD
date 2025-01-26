#pragma once
#include "ICommand.h"

class Toolbar;

class AddTriangleCommand : public ICommand
{
public:
	AddTriangleCommand(Toolbar* toolbar)
		: m_toolbar(toolbar)
	{}

	void Execute() const override;

private:
	Toolbar* m_toolbar;
};

