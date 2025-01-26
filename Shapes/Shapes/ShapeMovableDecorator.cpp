#include "ShapeMovableDecorator.h"

std::string ShapeMovableDecorator::ToString() const
{
    return m_shape->ToString();
}

void ShapeMovableDecorator::Draw(sf::RenderWindow& window) const
{
    m_shape->Draw(window);
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

void ShapeMovableDecorator::AddOutlineThickness()
{
    m_shape->AddOutlineThickness();
}

void ShapeMovableDecorator::ReduceOutlineThickness()
{
    m_shape->ReduceOutlineThickness();
}

void ShapeMovableDecorator::SetFillColor(sf::Color color)
{
    m_shape->SetFillColor(color);
}

void ShapeMovableDecorator::SetOutlineColor(sf::Color color)
{
    m_shape->SetOutlineColor(color);
}

sf::Color ShapeMovableDecorator::GetFillColor() const
{
    return m_shape->GetFillColor();
}

sf::Color ShapeMovableDecorator::GetOutlineColor() const
{
    return m_shape->GetOutlineColor();
}
