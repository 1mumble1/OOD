#pragma once
#include "stdafx.h"

class ShapeController
{
public:
    void ReadShapes(const std::string& fileName);

    void DrawShapes();

    void PrintShapesInfo(const std::string& fileName);

private:
    const int WIDTH_WINDOW = 1500;
    const int HEIGHT_WINDOW = 900;
    const std::string TITLE_WINDOW = "Window";

    std::vector<std::shared_ptr<IShape>> m_shapes = {};
    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);

    IShapePtr ConstructShape(const std::string& line);

};

