#include "CRectangleShape.h"

const std::string CRectangleShape::NAME = RECTANGLE_SHAPE_NAME;

std::string CRectangleShape::ToString() const
{
    return NAME;
}

void CRectangleShape::Draw(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
}

void CRectangleShape::SetFillColor(const sf::Color newColor)
{
    m_rectangle.setFillColor(newColor);
}

void CRectangleShape::SetOutlineColor(const sf::Color newColor)
{
    m_rectangle.setOutlineColor(newColor);
}

void CRectangleShape::AddOutlineThickness()
{
    float thickness = GetThickness();
    thickness++;
    m_rectangle.setOutlineThickness(thickness);
}

void CRectangleShape::ReduceOutlineThickness()
{
    float thickness = GetThickness();
    if (thickness >= MIN_THICKNESS)
    {
        thickness--;
    }
    m_rectangle.setOutlineThickness(thickness);
}

sf::Color CRectangleShape::GetFillColor() const
{
    return m_rectangle.getFillColor();
}

sf::Color CRectangleShape::GetOutlineColor() const
{
    return m_rectangle.getOutlineColor();
}

float CRectangleShape::GetThickness() const
{
    return m_rectangle.getOutlineThickness();
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

IShapePtr CRectangleShape::Clone() const
{
    return std::make_shared<CRectangleShape>(*this);
}

