#include "ShapeMathDecorator.h"

float ShapeMathDecorator::GetArea() const
{
    return m_area;
}

float ShapeMathDecorator::GetPerimeter() const
{
    return m_perimeter;
}

std::string ShapeMathDecorator::ToString() const
{
    std::ostringstream iss;
    iss << m_shape->ToString() << ": P=" << GetPerimeter() << "; S=" << GetArea();
    return iss.str();
}

void ShapeMathDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void ShapeMathDecorator::Move(const sf::Vector2f& offset)
{
    m_shape->Move(offset);
}

bool ShapeMathDecorator::Contains(const sf::Vector2f& point) const
{
    return m_shape->Contains(point);
}

sf::Vector2f ShapeMathDecorator::GetPosition() const
{
    return m_shape->GetPosition();
}

sf::Vector2f ShapeMathDecorator::GetSize() const
{
    return m_shape->GetSize();
}

void ShapeMathDecorator::SetPerimeter()
{
    m_perimeter = CalculatePerimeter();
}

void ShapeMathDecorator::SetArea()
{
    m_area = CalculateArea();
}
