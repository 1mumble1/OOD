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

void CTriangleShape::Move(const sf::Vector2f& offset)
{
	m_triangle.move(offset);
}

bool CTriangleShape::Contains(const sf::Vector2f& point) const
{
	return m_triangle.getGlobalBounds().contains(point);
}

sf::Vector2f CTriangleShape::GetPosition() const
{
	return m_triangle.getGlobalBounds().getPosition();
}

sf::Vector2f CTriangleShape::GetSize() const
{
	return m_triangle.getGlobalBounds().getSize();
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

void CTriangleShape::AddOutlineThickness()
{
	float thickness = m_triangle.getOutlineThickness();
	if (thickness >= 5)
	{
		return;
	}

	thickness++;
	m_triangle.setOutlineThickness(thickness);
}

void CTriangleShape::ReduceOutlineThickness()
{
	float thickness = m_triangle.getOutlineThickness();
	if (thickness <= 1)
	{
		return;
	}

	thickness--;
	m_triangle.setOutlineThickness(thickness);
}

void CTriangleShape::SetFillColor(sf::Color color)
{
	m_triangle.setFillColor(color);
}

void CTriangleShape::SetOutlineColor(sf::Color color)
{
	m_triangle.setOutlineColor(color);
}

sf::Color CTriangleShape::GetFillColor() const
{
	return m_triangle.getFillColor();
}

sf::Color CTriangleShape::GetOutlineColor() const
{
	return m_triangle.getOutlineColor();
}
