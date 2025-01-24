#pragma once
#include "ICommand.h"

class Toolbar;

class SetGreenColorCommand : public ICommand
{
public:
    SetGreenColorCommand(Toolbar* toolbar)
        : m_toolbar(toolbar)
    {}

    void Execute() const override;

private:
    Toolbar* m_toolbar;
};