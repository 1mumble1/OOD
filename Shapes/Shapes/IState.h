#pragma once

class Toolbar;

class IState
{
public:
    virtual ~IState() = default;

    virtual void DragAndDrop(Toolbar* toolbar) const = 0;
    virtual void FillShape(Toolbar* toolbar) const = 0;
    virtual void FillOutline(Toolbar* toolbar) const = 0;
};

