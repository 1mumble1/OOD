#pragma once
#include "stdafx.h"
#include "ShapeMathDecorator.h"

class CTriangleMathDecorator : public ShapeMathDecorator
{
public:
	CTriangleMathDecorator(IShapePtr&& shape)
		: ShapeMathDecorator(std::move(shape))
	{
		SetArea();
		SetPerimeter();
	}

protected:
	float CalculatePerimeter() const override;
	float CalculateArea() const override;

private:
	float GetSide(const sf::Vector2f& vertex1, const sf::Vector2f& vertex2) const;
};

