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

void ShapeMathDecorator::SetFillColor(const sf::Color newColor)
{
    m_shape->SetFillColor(newColor);
}

void ShapeMathDecorator::SetOutlineColor(const sf::Color newColor)
{
    m_shape->SetOutlineColor(newColor);
}

void ShapeMathDecorator::AddOutlineThickness()
{
    m_shape->AddOutlineThickness();
}

void ShapeMathDecorator::ReduceOutlineThickness()
{
    m_shape->ReduceOutlineThickness();
}

sf::Color ShapeMathDecorator::GetFillColor() const
{
    return m_shape->GetFillColor();
}

sf::Color ShapeMathDecorator::GetOutlineColor() const
{
    return m_shape->GetOutlineColor();
}

float ShapeMathDecorator::GetThickness() const
{
    return m_shape->GetThickness();
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

IShapePtr ShapeMathDecorator::Clone() const
{
    auto clonedShape = m_shape->Clone();
    return std::make_shared<ShapeMathDecorator>(clonedShape);
}

void ShapeMathDecorator::SetPerimeter()
{
    m_perimeter = CalculatePerimeter();
}

void ShapeMathDecorator::SetArea()
{
    m_area = CalculateArea();
}
