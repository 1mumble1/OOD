#pragma once
#include "IState.h"

class Toolbar;

class FillOutlineState : public IState
{
public:
    void DragAndDrop(Toolbar* toolbar) const override;
    void FillShape(Toolbar* toolbar) const override;
    void FillOutline(Toolbar* toolbar) const override;
};

