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

	void Move(const sf::Vector2f& offset) override;
	bool Contains(const sf::Vector2f& point) const override;
	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetSize() const override;

	float GetRadius() const;
	sf::Vector2f GetCenter() const;

	void AddOutlineThickness() override;
	void ReduceOutlineThickness() override;
	void SetFillColor(sf::Color color) override;
	void SetOutlineColor(sf::Color color) override;
	sf::Color GetFillColor() const override;
	sf::Color GetOutlineColor() const override;

private:
	sf::CircleShape m_circle;
};

