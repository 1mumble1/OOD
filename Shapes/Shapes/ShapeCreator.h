#pragma once
#include "stdafx.h"
#include "CTriangleShape.h"
#include "CCircleShape.h"
#include "CRectangleShape.h"

class ShapeCreator
{
public:
    static IShapePtr CreateShape(const std::string& line);

private:
    static IShapePtr CreateRectangle(const std::string& info);

    static IShapePtr CreateTriangle(const std::string& info);

    static IShapePtr CreateCircle(const std::string& info);
};

