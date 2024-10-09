#pragma once
#include "stdafx.h"
#include "ShapeDecorator.h"

class CTriangleMathDecorator : public ShapeDecorator
{
public:
	CTriangleMathDecorator(IShapePtr&& shape)
		: ShapeDecorator(std::move(shape))
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

