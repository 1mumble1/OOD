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

bool CTriangleShape::Contains(const sf::Vector2f& point) const
{
	return m_triangle.getGlobalBounds().contains(point);
}

void CTriangleShape::Move(const sf::Vector2f& offset)
{
	m_triangle.move(offset);
}

sf::Vector2f CTriangleShape::GetPosition() const
{
	return m_triangle.getPosition();
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
