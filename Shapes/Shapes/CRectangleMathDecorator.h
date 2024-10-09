#pragma once
#include "stdafx.h"
#include "ShapeDecorator.h"

class CRectangleMathDecorator : public ShapeDecorator
{
public:
	CRectangleMathDecorator(IShapePtr&& shape)
		: ShapeDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	float CalculatePerimeter() const override;
	float CalculateArea() const override;
};

