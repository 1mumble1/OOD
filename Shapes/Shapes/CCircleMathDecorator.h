#pragma once
#include "stdafx.h"
#include "ShapeMathDecorator.h"

class CCircleMathDecorator : public ShapeMathDecorator
{
public:
	CCircleMathDecorator(IShapePtr&& shape)
		: ShapeMathDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	float CalculatePerimeter() const override;
	float CalculateArea() const override;
};

