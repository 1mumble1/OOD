#include "CRectangleShape.h"

const std::string CRectangleShape::NAME = "RECTANGLE";

std::string CRectangleShape::ToString() const
{
    return NAME;
}

void CRectangleShape::Draw(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
}

void CRectangleShape::Move(const sf::Vector2f& offset)
{
    m_rectangle.move(offset);
}

bool CRectangleShape::Contains(const sf::Vector2f& point) const
{
    return m_rectangle.getGlobalBounds().contains(point);
}

sf::Vector2f CRectangleShape::GetPosition() const
{
    return m_rectangle.getGlobalBounds().getPosition();
}

sf::Vector2f CRectangleShape::GetSize() const
{
    return m_rectangle.getGlobalBounds().getSize();
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

void CRectangleShape::AddOutlineThickness()
{
    float thickness = m_rectangle.getOutlineThickness();
    if (thickness >= 5)
    {
        return;
    }

    thickness++;
    m_rectangle.setOutlineThickness(thickness);
}

void CRectangleShape::ReduceOutlineThickness()
{
    float thickness = m_rectangle.getOutlineThickness();
    if (thickness <= 1)
    {
        return;
    }

    thickness--;
    m_rectangle.setOutlineThickness(thickness);
}

void CRectangleShape::SetFillColor(sf::Color color)
{
    m_rectangle.setFillColor(color);
}

void CRectangleShape::SetOutlineColor(sf::Color color)
{
    m_rectangle.setOutlineColor(color);
}

sf::Color CRectangleShape::GetFillColor() const
{
    return m_rectangle.getFillColor();
}

sf::Color CRectangleShape::GetOutlineColor() const
{
    return m_rectangle.getOutlineColor();
}

