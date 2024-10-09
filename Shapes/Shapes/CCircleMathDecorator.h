#pragma once
#include "stdafx.h"
#include "ShapeDecorator.h"

class CCircleMathDecorator : public ShapeDecorator
{
public:
	CCircleMathDecorator(IShapePtr&& shape)
		: ShapeDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	float CalculatePerimeter() const override;
	float CalculateArea() const override;
};

