#pragma once
#include "stdafx.h"
#include "CompositeShape.h"

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

    std::vector<IShapePtr> m_shapes = {};
    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);
    CompositeShape m_selectedShapes;
    sf::Vector2f m_dragOffset, m_dragStart;
    bool m_dragging = false;

    IShapePtr ConstructShape(const std::string& line);

    void ProcessEvents();
    void HandleMousePress(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseMove(const sf::Event::MouseMoveEvent& mouse);
    void HandleKeyPress(const sf::Event::KeyEvent& key);

};

