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

    float GetWidth() const;
    float GetHeight() const;

    std::shared_ptr<IShape> Clone() const override;

private:
	sf::RectangleShape m_rectangle;
};

