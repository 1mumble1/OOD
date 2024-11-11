#include "ShapeMovableDecorator.h"

std::string ShapeMovableDecorator::ToString() const
{
    return m_shape->ToString();
}

//void ShapeMovableDecorator::Draw(sf::RenderWindow& window) const
//{
//    m_shape->Draw(window);
//}
//
//void ShapeMovableDecorator::Move(const sf::Vector2f& offset)
//{
//    m_shape->Move(offset);
//}
//
//bool ShapeMovableDecorator::Contains(const sf::Vector2f& point) const
//{
//    return m_shape->Contains(point);
//}
//
//sf::Vector2f ShapeMovableDecorator::GetPosition() const
//{
//    return m_shape->GetPosition();
//}
//
//sf::Vector2f ShapeMovableDecorator::GetSize() const
//{
//    return m_shape->GetSize();
//}
