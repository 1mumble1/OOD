#include "CTriangleMathDecorator.h"
#include "CTriangleShape.h"

float CTriangleMathDecorator::CalculatePerimeter() const
{
    sf::Vector2f vertex1 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetFirstVertex();
    sf::Vector2f vertex2 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetSecondVertex();
    sf::Vector2f vertex3 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetThirdVertex();

    return CTriangleMathDecorator::GetSide(vertex1, vertex2) +
        CTriangleMathDecorator::GetSide(vertex2, vertex3) +
        CTriangleMathDecorator::GetSide(vertex3, vertex1);
}

float CTriangleMathDecorator::CalculateArea() const
{
    sf::Vector2f vertex1 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetFirstVertex();
    sf::Vector2f vertex2 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetSecondVertex();
    sf::Vector2f vertex3 = std::dynamic_pointer_cast<CTriangleShape>(m_shape)->GetThirdVertex();

	return 0.5f * abs(
		(vertex2.x - vertex1.x) *
		(vertex3.y - vertex1.y) -
		(vertex3.x - vertex1.x) *
		(vertex2.y - vertex1.y));
}

float CTriangleMathDecorator::GetSide(const sf::Vector2f& vertex1, const sf::Vector2f& vertex2) const
{
    return static_cast<float>(std::sqrt(std::pow(vertex1.x - vertex2.x, 2) + std::pow(vertex1.y - vertex2.y, 2)));
}
