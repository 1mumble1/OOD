#include "CCircleMathDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "CCircleShape.h"

float CCircleMathDecorator::CalculatePerimeter() const
{
    float radius = std::dynamic_pointer_cast<CCircleShape>(m_shape)->GetRadius();
    return static_cast<float>(2 * M_PI * radius);
}

float CCircleMathDecorator::CalculateArea() const
{
    float radius = std::dynamic_pointer_cast<CCircleShape>(m_shape)->GetRadius();
    return static_cast<float>(M_PI * radius * radius);
}
