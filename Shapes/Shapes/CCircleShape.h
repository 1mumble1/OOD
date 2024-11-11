#pragma once
#include "stdafx.h"
#include "ColorsGenerator.h"

class CCircleShape : public IShape
{
public:
	static const std::string NAME;

	CCircleShape(const sf::Vector2f& center, float radius)
	{
		m_circle.setRadius(radius);
		m_circle.setPosition(center);
		ColorsGenerator gen;
		m_circle.setFillColor(gen.GetRandomColor());
	}

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const override;

	bool Contains(const sf::Vector2f& point) const override;
	void Move(const sf::Vector2f& offset) override;
	sf::Vector2f GetPosition() const override;

	float GetRadius() const;
	sf::Vector2f GetCenter() const;

private:
	sf::CircleShape m_circle;
	bool m_selected = false;
};

