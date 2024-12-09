#include "CompositeShapeMovableDecorator.h"

void CompositeShapeMovableDecorator::Draw(sf::RenderWindow& window) const
{
    for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        shapePtr->Draw(window);
    }
}

void CompositeShapeMovableDecorator::Select()
{
    for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        shapePtr->Select();
    }
}

void CompositeShapeMovableDecorator::Deselect()
{
    for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        shapePtr->Deselect();
    }
}

bool CompositeShapeMovableDecorator::IsSelected() const
{
    for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->IsSelected())
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
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        shapePtr->Move(offset);
    }
}

bool CompositeShapeMovableDecorator::Contains(const sf::Vector2f& point) const
{
    for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->Contains(point))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2f CompositeShapeMovableDecorator::GetPosition() const
{
    return std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetPosition();
}

sf::Vector2f CompositeShapeMovableDecorator::GetSize() const
{
    return std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetSize();
}

std::vector<IShapePtr> CompositeShapeMovableDecorator::GetShapes()
{
    return std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes();
}
