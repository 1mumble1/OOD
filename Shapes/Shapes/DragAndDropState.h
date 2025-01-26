#pragma once
#include "IState.h"

class DragAndDropState : public IState
{
	void OnLeftMouseButtonPressed(ShapeHandler* handler, Toolbar* toolbar) const override
	{
		handler->SelectShape();
	}

	void OnLeftMouseButtonPressedWithShift(ShapeHandler* handler) const override
	{
		handler->SelectShapes();
	}

	void OnLeftMouseButtonReleased(ShapeHandler* handler) const override
	{
		handler->StopDragging();
	}

	void OnGroup(ShapeHandler* handler) const override
	{
		handler->GroupShapes();
	}

	void OnUngroup(ShapeHandler* handler) const override
	{
		handler->UngroupShapes();
	}

	void OnMouseMove(ShapeHandler* handler) const override
	{
		handler->Move();
	}
};