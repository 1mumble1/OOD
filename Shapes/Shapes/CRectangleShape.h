#pragma once
#include "stdafx.h"
#include "ColorsGenerator.h"

class CRectangleShape : public IShape
{
public:
	static const std::string NAME;

    CRectangleShape(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight)
    {
        m_rectangle.setSize(bottomRight - topLeft);
        m_rectangle.setPosition(topLeft);
        ColorsGenerator gen;
        m_rectangle.setFillColor(gen.GetRandomColor());
    }

    //float GetArea() const override;

    //float GetPerimeter() const override;

    std::string ToString() const override;

    void Draw(sf::RenderWindow& window) const override;

    float GetWidth() const;
    float GetHeight() const;

private:
	sf::RectangleShape m_rectangle;
};

