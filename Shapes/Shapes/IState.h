#pragma once
#include "ShapeHandler.h"

class IState
{
public:
	virtual void OnLeftMouseButtonPressed(ShapeHandler* handler, Toolbar* toolbar) const = 0;
	virtual void OnLeftMouseButtonPressedWithShift(ShapeHandler* handler) const = 0;
	virtual void OnLeftMouseButtonReleased(ShapeHandler* handler) const = 0;
	virtual void OnGroup(ShapeHandler* handler) const = 0;
	virtual void OnUngroup(ShapeHandler* handler) const = 0;
	virtual void OnMouseMove(ShapeHandler* handler) const = 0;
};