#pragma once
#include "stdafx.h"
#include "CTriangleShape.h"
#include "CCircleShape.h"
#include "CRectangleShape.h"

class ShapeCreator
{
public:
    static std::shared_ptr<IShape> CreateShape(const std::string& line);

private:
    static std::shared_ptr<IShape> CreateRectangle(const std::string& info);

    static std::shared_ptr<IShape> CreateTriangle(const std::string& info);

    static std::shared_ptr<IShape> CreateCircle(const std::string& info);
};

