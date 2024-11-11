#include "CompositeShape.h"

const std::string CompositeShape::NAME = "COMPOSITE";

std::string CompositeShape::ToString() const
{
    return NAME;
}

void CompositeShape::Draw(sf::RenderWindow& window) const
{
    for (auto& shape : m_shapes)
    {
        shape->Draw(window);
    }
}

void CompositeShape::AddShape(IShapePtr shape)
{
    m_shapes.push_back(shape);
}

void CompositeShape::RemoveShape(IShapePtr shape)
{
    m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

bool CompositeShape::Contains(const sf::Vector2f& point) const
{
    for (const auto& shape : m_shapes)
    {
        if (shape->Contains(point))
        {
            return true;
        }
    }
    return false;
}

void CompositeShape::Move(const sf::Vector2f& offset)
{
    for (auto& shape : m_shapes)
    {
        shape->Move(offset);
    }
}

sf::Vector2f CompositeShape::GetPosition() const
{
    return GetTopLeftPoint();
}

std::vector<IShapePtr> CompositeShape::GetShapes()
{
    return m_shapes;
}

void CompositeShape::SetShapes(std::vector<IShapePtr> newShapes)
{
    m_shapes = newShapes;
}

sf::Vector2f CompositeShape::GetTopLeftPoint() const
{
    if (m_shapes.empty())
    {
        return sf::Vector2f(0, 0);
    }

    sf::Vector2f topLeft = m_shapes[0]->GetPosition();
    for (auto const& shape : m_shapes)
    {
        if (shape->GetPosition().x < topLeft.x)
        {
            topLeft.x = shape->GetPosition().x;
        }

        if (shape->GetPosition().y < topLeft.y)
        {
            topLeft.y = shape->GetPosition().y;
        }
    }

    return topLeft;
}

