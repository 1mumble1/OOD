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

    std::string ToString() const override;

    void Draw(sf::RenderWindow& window) const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Move(const sf::Vector2f& offset) override;
    sf::Vector2f GetPosition() const override;

    float GetWidth() const;
    float GetHeight() const;

private:
	sf::RectangleShape m_rectangle;
    bool m_selected = false;
};

