#include "CTriangleShape.h"

const std::string CTriangleShape::NAME = TRIANGLE_SHAPE_NAME;

std::string CTriangleShape::ToString() const
{
	return NAME;
}

void CTriangleShape::Draw(sf::RenderWindow& window) const
{
	window.draw(m_triangle);
}

void CTriangleShape::SetFillColor(const sf::Color newColor)
{
	m_triangle.setFillColor(newColor);
}

void CTriangleShape::SetOutlineColor(const sf::Color newColor)
{
	m_triangle.setOutlineColor(newColor);
}

void CTriangleShape::AddOutlineThickness()
{
	float thickness = GetThickness();
	thickness++;
	m_triangle.setOutlineThickness(thickness);
}

void CTriangleShape::ReduceOutlineThickness()
{
	float thickness = GetThickness();
	if (thickness >= MIN_THICKNESS)
	{
		thickness--;
	}
	m_triangle.setOutlineThickness(thickness);
}

sf::Color CTriangleShape::GetFillColor() const
{
	return m_triangle.getFillColor();
}

sf::Color CTriangleShape::GetOutlineColor() const
{
	return m_triangle.getOutlineColor();
}

float CTriangleShape::GetThickness() const
{
	return m_triangle.getOutlineThickness();
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
	return m_triangle.getPoint(ID_OF_FIRST_VERTEX_FOR_TRIANGLE);
}

sf::Vector2f CTriangleShape::GetSecondVertex() const
{
	return m_triangle.getPoint(ID_OF_SECOND_VERTEX_FOR_TRIANGLE);
}

sf::Vector2f CTriangleShape::GetThirdVertex() const
{
	return m_triangle.getPoint(ID_OF_THIRD_VERTEX_FOR_TRIANGLE);
}

IShapePtr CTriangleShape::Clone() const
{
	return std::make_shared<CTriangleShape>(*this);
}
