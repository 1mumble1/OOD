#include "CompositeShape.h"

const std::string CompositeShape::NAME = COMPOSITE_SHAPE_NAME;

std::string CompositeShape::ToString() const
{
    std::ostringstream infoStream(NAME);
    infoStream << std::endl;
    for (auto const& shape : m_shapes)
    {
        infoStream << TABULATION << shape->ToString() << std::endl;
    }

    return infoStream.str();
}

void CompositeShape::Draw(sf::RenderWindow& window) const
{
    for (auto const& shape : m_shapes)
    {
        shape->Draw(window);
    }
}

void CompositeShape::SetFillColor(const sf::Color newColor)
{
    for (auto const& shape : m_shapes)
    {
        shape->SetFillColor(newColor);
    }
}

void CompositeShape::SetOutlineColor(const sf::Color newColor)
{
    for (auto const& shape : m_shapes)
    {
        shape->SetOutlineColor(newColor);
    }
}

void CompositeShape::AddOutlineThickness()
{
    for (auto& shape : m_shapes)
    {
        shape->AddOutlineThickness();
    }
}

void CompositeShape::ReduceOutlineThickness()
{
    for (auto& shape : m_shapes)
    {
        shape->ReduceOutlineThickness();
    }
}

sf::Color CompositeShape::GetFillColor() const
{
    if (m_shapes.empty())
    {
        return sf::Color::Black;
    }
    return m_shapes[0]->GetFillColor();
}

sf::Color CompositeShape::GetOutlineColor() const
{
    if (m_shapes.empty())
    {
        return sf::Color::Black;
    }
    return m_shapes[0]->GetOutlineColor();
}

float CompositeShape::GetThickness() const
{
    if (m_shapes.empty())
    {
        return 0.0f;
    }
    return m_shapes[0]->GetThickness();
}

std::string CompositeShape::ToStringShapes() const
{
    std::ostringstream ss;
    for (auto const& shape : m_shapes)
    {
        ss << shape->ToString();
    }

    return ss.str();
}

void CompositeShape::AddShape(IShapePtr shape)
{
    m_shapes.push_back(shape);
}

void CompositeShape::RemoveShape(IShapePtr shape)
{
    m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
}

std::vector<IShapePtr> CompositeShape::GetShapes()
{
    return m_shapes;
}

void CompositeShape::SetShapes(std::vector<IShapePtr> newShapes)
{
    m_shapes = newShapes;
}

void CompositeShape::Move(const sf::Vector2f& offset)
{
    for (auto& shape : m_shapes)
    {
        shape->Move(offset);
    }
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

sf::Vector2f CompositeShape::GetPosition() const
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

sf::Vector2f CompositeShape::GetSize() const
{
    return sf::Vector2f();
}

IShapePtr CompositeShape::Clone() const
{
    return std::make_shared<CompositeShape>(*this);
}


