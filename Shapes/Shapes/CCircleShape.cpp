#include "CCircleShape.h"


const std::string CCircleShape::NAME = "CIRCLE";

//float CCircleShape::GetArea() const
//{
//	return static_cast<float>(M_PI * m_circle.getRadius() * m_circle.getRadius());
//}
//
//float CCircleShape::GetPerimeter() const
//{
//	return static_cast<float>(2 * M_PI * m_circle.getRadius());
//}
//
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
