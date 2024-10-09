#include "CRectangleMathDecorator.h"
#include "CRectangleShape.h"

float CRectangleMathDecorator::CalculatePerimeter() const
{
	float width = std::dynamic_pointer_cast<CRectangleShape>(m_shape)->GetWidth();
	float height = std::dynamic_pointer_cast<CRectangleShape>(m_shape)->GetHeight();
	return static_cast<float>(2 * (width + height));
}

float CRectangleMathDecorator::CalculateArea() const
{
	float width = std::dynamic_pointer_cast<CRectangleShape>(m_shape)->GetWidth();
	float height = std::dynamic_pointer_cast<CRectangleShape>(m_shape)->GetHeight();
	return static_cast<float>(width * height);
}
