#pragma once
#include "stdafx.h"
#include "ShapeMathDecorator.h"

class CRectangleMathDecorator : public ShapeMathDecorator
{
public:
	CRectangleMathDecorator(IShapePtr&& shape)
		: ShapeMathDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	float CalculatePerimeter() const override;
	float CalculateArea() const override;
};

