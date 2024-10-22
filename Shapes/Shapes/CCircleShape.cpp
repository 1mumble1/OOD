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

float CCircleShape::GetRadius() const
{
	return m_circle.getRadius();
}

sf::Vector2f CCircleShape::GetCenter() const
{
	return m_circle.getPosition();
}
