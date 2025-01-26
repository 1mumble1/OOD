#pragma once
#include "stdafx.h"
#include "ColorsGenerator.h"

class CTriangleShape : public IShape
{
public:
	static const std::string NAME;

	CTriangleShape(const sf::Vector2f& vertex1,
		const sf::Vector2f& vertex2,
		const sf::Vector2f& vertex3)
	{
		m_triangle.setPointCount(3);
		m_triangle.setPoint(0, vertex1);
		m_triangle.setPoint(1, vertex2);
		m_triangle.setPoint(2, vertex3);
		ColorsGenerator gen;
		m_triangle.setFillColor(gen.GetRandomColor());
	}

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const override;

	void Move(const sf::Vector2f& offset) override;
	bool Contains(const sf::Vector2f& point) const override;
	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetSize() const override;

	sf::Vector2f GetFirstVertex() const;
	sf::Vector2f GetSecondVertex() const;
	sf::Vector2f GetThirdVertex() const;

	void AddOutlineThickness() override;
	void ReduceOutlineThickness() override;
	void SetFillColor(sf::Color color) override;
	void SetOutlineColor(sf::Color color) override;
	sf::Color GetFillColor() const override;
	sf::Color GetOutlineColor() const override;

private:
	sf::ConvexShape m_triangle;
};

