#include "ShapeCreator.h"

IShapePtr ShapeCreator::CreateShape(const std::string& line)
{
    std::regex pattern(R"(^(\w+):\s*(.*)$)");
    std::smatch matches;

    std::string nameOfShape, info;
    if (std::regex_search(line, matches, pattern))
    {
        nameOfShape = matches[1].str();
        info = matches[2].str();
    }

    if (nameOfShape == CCircleShape::NAME)
    {
        return ShapeCreator::CreateCircle(info);
    }
    else if (nameOfShape == CTriangleShape::NAME)
    {
        return ShapeCreator::CreateTriangle(info);
    }
    else if (nameOfShape == CRectangleShape::NAME)
    {
        return ShapeCreator::CreateRectangle(info);
    }

    return nullptr;
}

std::shared_ptr<IShape> ShapeCreator::CreateCircle(const std::string& info)
{
    float centerX, centerY, radius;
    std::regex pattern(R"(^C=(\d+),(\d+);\s*R=(\d+)$)");
    std::smatch matches;

    if (std::regex_search(info, matches, pattern))
    {
        centerX = std::stoi(matches[1].str());
        centerY = std::stoi(matches[2].str());
        radius = std::stoi(matches[3].str());
    }
    else
    {
        std::cout << "Invalid circle coordinates or sizes" << std::endl;
        return nullptr;
    }

    sf::Vector2f center = { centerX, centerY };
    return std::make_shared<CCircleShape>(center, radius);
}

std::shared_ptr<IShape> ShapeCreator::CreateRectangle(const std::string& info)
{
    float leftTopX, leftTopY, rightBottomX, rightBottomY;
    std::regex pattern(R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+)$)");
    std::smatch matches;

    if (std::regex_search(info, matches, pattern))
    {
        leftTopX = std::stoi(matches[1].str());
        leftTopY = std::stoi(matches[2].str());
        rightBottomX = std::stoi(matches[3].str());
        rightBottomY = std::stoi(matches[4].str());
    }
    else
    {
        std::cout << "Invalid rectangle coordinates" << std::endl;
        return nullptr;
    }

    sf::Vector2f leftTop = { leftTopX, leftTopY };
    sf::Vector2f rightBottom = { rightBottomX, rightBottomY };
    return std::make_shared<CRectangleShape>(leftTop, rightBottom);
}

std::shared_ptr<IShape> ShapeCreator::CreateTriangle(const std::string& info)
{
    float vertex1X, vertex1Y;
    float vertex2X, vertex2Y;
    float vertex3X, vertex3Y;

    std::regex pattern(R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+);\s*P3=(\d+),(\d+)$)");
    std::smatch matches;

    if (std::regex_search(info, matches, pattern))
    {
        vertex1X = std::stoi(matches[1].str());
        vertex1Y = std::stoi(matches[2].str());
        vertex2X = std::stoi(matches[3].str());
        vertex2Y = std::stoi(matches[4].str());
        vertex3X = std::stoi(matches[5].str());
        vertex3Y = std::stoi(matches[6].str());
    }
    else
    {
        std::cout << "Invalid triangle coordinates" << std::endl;
        return nullptr;
    }

    sf::Vector2f vertex1 = { vertex1X, vertex1Y };
    sf::Vector2f vertex2 = { vertex2X, vertex2Y };
    sf::Vector2f vertex3 = { vertex3X, vertex3Y };

    return std::make_shared<CTriangleShape>(vertex1, vertex2, vertex3);
}