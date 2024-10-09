#pragma once
#include "stdafx.h"

class ShapeDecorator : public IShape
{
public:
    ShapeDecorator(IShapePtr&& shape)
        : m_shape(std::move(shape))
    {}

    float GetArea() const;

    float GetPerimeter() const;

    virtual std::string ToString() const;

    void Draw(sf::RenderWindow& window) const override;

protected:
    virtual float CalculatePerimeter() const = 0;
    virtual float CalculateArea() const = 0;
    void SetPerimeter();
    void SetArea();
    IShapePtr m_shape;

private:
    float m_perimeter = 0.0f, m_area = 0.0f;
};