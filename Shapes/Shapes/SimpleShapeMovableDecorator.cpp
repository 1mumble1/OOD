#include "SimpleShapeMovableDecorator.h"

void SimpleShapeMovableDecorator::Draw(sf::RenderWindow& window) const
{
    if (m_selected)
    {
        sf::RectangleShape rect;
        auto pos = m_shape->GetPosition();
        auto size = m_shape->GetSize();
        rect.setPosition(pos);
        rect.setSize(size);
        rect.setOutlineColor(sf::Color::Black);
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Transparent);
        window.draw(rect);
    }
    m_shape->Draw(window);
}

void SimpleShapeMovableDecorator::SetFillColor(const sf::Color newColor)
{
    m_shape->SetFillColor(newColor);
}

void SimpleShapeMovableDecorator::SetOutlineColor(const sf::Color newColor)
{
    m_shape->SetOutlineColor(newColor);
}

void SimpleShapeMovableDecorator::AddOutlineThickness()
{
    m_shape->AddOutlineThickness();
}

void SimpleShapeMovableDecorator::ReduceOutlineThickness()
{
    m_shape->ReduceOutlineThickness();
}

sf::Color SimpleShapeMovableDecorator::GetFillColor() const
{
    return m_shape->GetFillColor();
}

sf::Color SimpleShapeMovableDecorator::GetOutlineColor() const
{
    return m_shape->GetOutlineColor();
}

float SimpleShapeMovableDecorator::GetThickness() const
{
    return m_shape->GetThickness();
}

void SimpleShapeMovableDecorator::Select()
{
	m_selected = true;
}

void SimpleShapeMovableDecorator::Deselect()
{
	m_selected = false;
}

bool SimpleShapeMovableDecorator::IsSelected() const
{
	return m_selected;
}

void SimpleShapeMovableDecorator::Move(const sf::Vector2f& offset)
{
	std::dynamic_pointer_cast<IShape>(m_shape)->Move(offset);
}

bool SimpleShapeMovableDecorator::Contains(const sf::Vector2f& point) const
{
	return std::dynamic_pointer_cast<IShape>(m_shape)->Contains(point);
}

sf::Vector2f SimpleShapeMovableDecorator::GetPosition() const
{
	return std::dynamic_pointer_cast<IShape>(m_shape)->GetPosition();
}

sf::Vector2f SimpleShapeMovableDecorator::GetSize() const
{
    return std::dynamic_pointer_cast<IShape>(m_shape)->GetSize();
}
