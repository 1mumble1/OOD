#pragma once
#include "stdafx.h"

class ShapeMathDecorator : public IShape
{
public:
    ShapeMathDecorator(IShapePtr&& shape)
        : m_shape(std::move(shape))
    {}

    float GetArea() const;

    float GetPerimeter() const;

    virtual std::string ToString() const;

    void Draw(sf::RenderWindow& window) const override;
    void SetFillColor(const sf::Color newColor) override;
    void SetOutlineColor(const sf::Color newColor) override;
    void AddOutlineThickness() override;
    void ReduceOutlineThickness() override;
    sf::Color GetFillColor() const override;
    sf::Color GetOutlineColor() const override;
    float GetThickness() const override;


    void Move(const sf::Vector2f& offset) override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    sf::Vector2f GetSize() const override;

protected:
    virtual float CalculatePerimeter() const = 0;
    virtual float CalculateArea() const = 0;
    void SetPerimeter();
    void SetArea();
    IShapePtr m_shape;

private:
    float m_perimeter = 0.0f, m_area = 0.0f;
};