#pragma once
#include "stdafx.h"
#include "CompositeShape.h"

class ShapeController
{
public:
    ShapeController(const std::string& inputFileName, const std::string& outputFileName)
        : m_inputFileName(inputFileName)
        , m_outputFileName(outputFileName)
    {}

    void ReadShapes();

    void DrawShapes();

    void PrintShapesInfo();

private:
    const int WIDTH_WINDOW = 1500;
    const int HEIGHT_WINDOW = 900;
    const std::string TITLE_WINDOW = "Window";

    std::string m_inputFileName, m_outputFileName;

    std::vector<IShapePtr> m_shapes = {};
    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);
    sf::Vector2f m_dragStart;
    bool m_dragging = false;

    IShapePtr ConstructShape(const std::string& line);

    void ProcessEvents();
    void HandleMousePress(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseMove(const sf::Event::MouseMoveEvent& mouse);
    void HandleKeyPress(const sf::Event::KeyEvent& key);
    void DeselectAllShapes();
};

