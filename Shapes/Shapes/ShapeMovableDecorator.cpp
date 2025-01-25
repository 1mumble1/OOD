#include "ShapeMovableDecorator.h"

std::string ShapeMovableDecorator::ToString() const
{
    return m_shape->ToString();
}

void ShapeMovableDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
}

void ShapeMovableDecorator::SetFillColor(const sf::Color newColor)
{
    m_shape->SetFillColor(newColor);
}

void ShapeMovableDecorator::SetOutlineColor(const sf::Color newColor)
{
    m_shape->SetOutlineColor(newColor);
}

void ShapeMovableDecorator::AddOutlineThickness()
{
    m_shape->AddOutlineThickness();
}

void ShapeMovableDecorator::ReduceOutlineThickness()
{
    m_shape->ReduceOutlineThickness();
}

sf::Color ShapeMovableDecorator::GetFillColor() const
{
    return m_shape->GetFillColor();
}

sf::Color ShapeMovableDecorator::GetOutlineColor() const
{
    return m_shape->GetOutlineColor();
}

float ShapeMovableDecorator::GetThickness() const
{
    return m_shape->GetThickness();
}

void ShapeMovableDecorator::Move(const sf::Vector2f& offset)
{
    m_shape->Move(offset);
}

bool ShapeMovableDecorator::Contains(const sf::Vector2f& point) const
{
    return m_shape->Contains(point);
}

sf::Vector2f ShapeMovableDecorator::GetPosition() const
{
    return m_shape->GetPosition();
}

sf::Vector2f ShapeMovableDecorator::GetSize() const
{
    return m_shape->GetSize();
}

IShapePtr ShapeMovableDecorator::Clone() const
{
    auto clonedShape = m_shape->Clone();
    return std::make_shared<ShapeMovableDecorator>(clonedShape);
}
