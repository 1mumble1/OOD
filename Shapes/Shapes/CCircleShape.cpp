#include "CCircleShape.h"

const std::string CCircleShape::NAME = "CIRCLE";

std::string CCircleShape::ToString() const
{
	return NAME;
}

void CCircleShape::Draw(sf::RenderWindow& window) const
{
	window.draw(m_circle);
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
	return m_circle.getPosition();
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
