#include "ShapeDecorator.h"

float ShapeDecorator::GetArea() const
{
    return m_area;
}

float ShapeDecorator::GetPerimeter() const
{
    return m_perimeter;
}

std::string ShapeDecorator::ToString() const
{
    std::ostringstream iss;
    iss << m_shape->ToString() << ": P=" << GetPerimeter() << "; S=" << GetArea();
    return iss.str();
}

void ShapeDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void ShapeDecorator::SetPerimeter()
{
    m_perimeter = CalculatePerimeter();
}

void ShapeDecorator::SetArea()
{
    m_area = CalculateArea();
}
