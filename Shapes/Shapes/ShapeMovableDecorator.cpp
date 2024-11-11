#include "ShapeMovableDecorator.h"

std::string ShapeMovableDecorator::ToString() const
{
	return m_shape->ToString();
}

void ShapeMovableDecorator::Draw(sf::RenderWindow& window) const
{
	m_shape->Draw(window);
}

void ShapeMovableDecorator::Select()
{
	m_selected = true;
}

void ShapeMovableDecorator::Deselect()
{
	m_selected = false;
}

bool ShapeMovableDecorator::IsSelected() const
{
	return m_selected;
}

bool ShapeMovableDecorator::Contains(const sf::Vector2f& point) const
{
	return m_shape->Contains(point);
}

void ShapeMovableDecorator::Move(const sf::Vector2f& offset)
{
	m_shape->Move(offset);
}

sf::Vector2f ShapeMovableDecorator::GetPosition() const
{
	return m_shape->GetPosition();
}


