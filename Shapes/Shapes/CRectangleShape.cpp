#include "CRectangleShape.h"

const std::string CRectangleShape::NAME = "RECTANGLE";

//float CRectangleShape::GetArea() const
//{
//    sf::Vector2f size = m_rectangle.getSize();
//    return size.x * size.y;
//}
//
//float CRectangleShape::GetPerimeter() const
//{
//    sf::Vector2f size = m_rectangle.getSize();
//    return 2 * (size.x + size.y);
//}
//
std::string CRectangleShape::ToString() const
{
    return NAME;
}

void CRectangleShape::Draw(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
}

float CRectangleShape::GetWidth() const
{
    sf::Vector2f size = m_rectangle.getSize();
    return size.x;
}

float CRectangleShape::GetHeight() const
{
    sf::Vector2f size = m_rectangle.getSize();
    return size.y;
}

