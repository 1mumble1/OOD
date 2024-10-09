#include "CTriangleShape.h"

const std::string CTriangleShape::NAME = "TRIANGLE";

//float CTriangleShape::GetSide(const sf::Vector2f& vertex1, const sf::Vector2f& vertex2) const
//{
//	return static_cast<float>(std::sqrt(std::pow(vertex1.x - vertex2.x, 2) + std::pow(vertex1.y - vertex2.y, 2)));
//}
//
//float CTriangleShape::GetArea() const
//{
//	return 0.5f * abs(
//		(m_triangle.getPoint(1).x - m_triangle.getPoint(0).x) *
//		(m_triangle.getPoint(2).y - m_triangle.getPoint(0).y) -
//		(m_triangle.getPoint(2).x - m_triangle.getPoint(0).x) *
//		(m_triangle.getPoint(1).y - m_triangle.getPoint(0).y));
//}
//
//float CTriangleShape::GetPerimeter() const
//{
//	return CTriangleShape::GetSide(m_triangle.getPoint(0), m_triangle.getPoint(1)) +
//		CTriangleShape::GetSide(m_triangle.getPoint(1), m_triangle.getPoint(2)) +
//		CTriangleShape::GetSide(m_triangle.getPoint(2), m_triangle.getPoint(0));
//}
//
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
