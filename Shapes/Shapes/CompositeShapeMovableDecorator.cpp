#include "CompositeShapeMovableDecorator.h"
#include "CompositeShape.h"

void CompositeShapeMovableDecorator::Select()
{
	for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
	{
		std::dynamic_pointer_cast<ShapeMovableDecorator>(shape)->Select();
	}
}

void CompositeShapeMovableDecorator::Deselect()
{
	for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
	{
		std::dynamic_pointer_cast<ShapeMovableDecorator>(shape)->Deselect();
	}
}

bool CompositeShapeMovableDecorator::IsSelected() const
{
	for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
	{
		if (std::dynamic_pointer_cast<ShapeMovableDecorator>(shape)->IsSelected())
		{
			return true;
		}
	}
	return false;
}

bool CompositeShapeMovableDecorator::Contains(const sf::Vector2f& point) const
{
	for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
	{
		if (std::dynamic_pointer_cast<ShapeMovableDecorator>(shape)->Contains(point))
		{
			return true;
		}
	}
	return false;
}

void CompositeShapeMovableDecorator::Move(const sf::Vector2f& offset)
{
	for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
	{
		std::dynamic_pointer_cast<ShapeMovableDecorator>(shape)->Move(offset);
	}
}

sf::Vector2f CompositeShapeMovableDecorator::GetPosition() const
{
	std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetPosition();
}
