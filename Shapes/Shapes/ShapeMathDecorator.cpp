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

void ShapeMathDecorator::SetPerimeter()
{
    m_perimeter = CalculatePerimeter();
}

void ShapeMathDecorator::SetArea()
{
    m_area = CalculateArea();
}
