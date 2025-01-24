#pragma once
#include "ICommand.h"

class Toolbar;

class SetRedColorCommand : public ICommand
{
public:
    SetRedColorCommand(Toolbar* toolbar) 
        : m_toolbar(toolbar) 
    {}

    void Execute() const override;

private:
    Toolbar* m_toolbar;
};