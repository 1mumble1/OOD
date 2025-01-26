#pragma once
#include "IState.h"

class FillColorState : public IState
{
	void OnLeftMouseButtonPressed(ShapeHandler* handler, Toolbar* toolbar) const override
	{
		//handler->FillColor(toolbar->GetColor());
	}

	void OnLeftMouseButtonPressedWithShift(ShapeHandler* handler) const override
	{
	}

	void OnLeftMouseButtonReleased(ShapeHandler* handler) const override
	{
	}

	void OnGroup(ShapeHandler* handler) const override
	{
	}

	void OnUngroup(ShapeHandler* handler) const override
	{
	}

	void OnMouseMove(ShapeHandler* handler) const override
	{
	}
};