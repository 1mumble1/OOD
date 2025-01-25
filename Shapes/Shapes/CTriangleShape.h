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
		m_triangle.setPointCount(COUNT_OF_VERTEX_FOR_TRIANGLE);
		m_triangle.setPoint(ID_OF_FIRST_VERTEX_FOR_TRIANGLE, vertex1);
		m_triangle.setPoint(ID_OF_SECOND_VERTEX_FOR_TRIANGLE, vertex2);
		m_triangle.setPoint(ID_OF_THIRD_VERTEX_FOR_TRIANGLE, vertex3);
		ColorsGenerator gen;
		m_triangle.setFillColor(gen.GetRandomColor());
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

	sf::Vector2f GetFirstVertex() const;
	sf::Vector2f GetSecondVertex() const;
	sf::Vector2f GetThirdVertex() const;

	std::shared_ptr<IShape> Clone() const override;

private:
	sf::ConvexShape m_triangle;
};