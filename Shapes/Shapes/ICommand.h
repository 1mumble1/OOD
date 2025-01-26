#pragma once
#include "stdafx.h"

class ICommand
{
public:
	virtual void Execute() const = 0;
};

