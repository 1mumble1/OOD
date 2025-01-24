#include "CCircleShape.h"

const std::string CCircleShape::NAME = CIRCLE_SHAPE_NAME;

std::string CCircleShape::ToString() const
{
	return NAME;
}

void CCircleShape::Draw(sf::RenderWindow& window) const
{
	window.draw(m_circle);
}

void CCircleShape::SetFillColor(const sf::Color newColor)
{
	m_circle.setFillColor(newColor);
}

void CCircleShape::SetOutlineColor(const sf::Color newColor)
{
	m_circle.setOutlineColor(newColor);
}

void CCircleShape::AddOutlineThickness()
{
	float thickness = GetThickness();
	thickness++;
	m_circle.setOutlineThickness(thickness);
}

void CCircleShape::ReduceOutlineThickness()
{
	float thickness = GetThickness();
	if (thickness >= MIN_THICKNESS)
	{
		thickness--;
	}
	m_circle.setOutlineThickness(thickness);
}

sf::Color CCircleShape::GetFillColor() const
{
	return m_circle.getFillColor();
}

sf::Color CCircleShape::GetOutlineColor() const
{
	return m_circle.getOutlineColor();
}

float CCircleShape::GetThickness() const
{
	return m_circle.getOutlineThickness();
}

void CCircleShape::Move(const sf::Vector2f& offset)
{
	m_circle.move(offset);
}

bool CCircleShape::Contains(const sf::Vector2f& point) const
{
	return m_circle.getGlobalBounds().contains(point);
}

sf::Vector2f CCircleShape::GetPosition() const
{
	return m_circle.getGlobalBounds().getPosition();
}

sf::Vector2f CCircleShape::GetSize() const
{
	return m_circle.getGlobalBounds().getSize();
}

float CCircleShape::GetRadius() const
{
	return m_circle.getRadius();
}

sf::Vector2f CCircleShape::GetCenter() const
{
	return m_circle.getPosition();
}
