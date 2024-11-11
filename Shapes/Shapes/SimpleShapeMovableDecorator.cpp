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
        rect.setOutlineColor(sf::Color::Blue);
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Transparent);
        window.draw(rect);
    }
    m_shape->Draw(window);
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
