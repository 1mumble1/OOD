#include "CTriangleShape.h"

const std::string CTriangleShape::NAME = "TRIANGLE";

std::string CTriangleShape::ToString() const
{
	return NAME;
}

void CTriangleShape::Draw(sf::RenderWindow& window) const
{
	window.draw(m_triangle);
}

sf::Vector2f CTriangleShape::GetFirstVertex() const
{
	return m_triangle.getPoint(0);
}

sf::Vector2f CTriangleShape::GetSecondVertex() const
{
	return m_triangle.getPoint(1);
}

sf::Vector2f CTriangleShape::GetThirdVertex() const
{
	return m_triangle.getPoint(2);
}
