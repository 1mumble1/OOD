#pragma once
#include "stdafx.h"
#include "CompositeShape.h"
#include "ShapeHandler.h"
#include "Toolbar.h"
#include "History.h"

class ShapeController
{
public:
    ShapeController(const ShapeController&) = delete;
    void operator=(const ShapeController&) = delete;
    static ShapeController& GetInstance();

    void ReadShapes(const std::string& fileName);

    void DrawShapes();

    void PrintShapesInfo(const std::string& fileName);

private:
    ShapeController()
    {
        m_handler = new ShapeHandler(m_window);
        m_toolBar = new Toolbar(m_window, m_handler);
        m_history = new History();
    };

    void SaveChanges();

    ShapeHandler* m_handler;
    Toolbar* m_toolBar;
    History* m_history;

    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);
    sf::Vector2f m_dragStart;
    bool m_dragging = INITIAL_DRAGGING_VALUE;

    IShapePtr ConstructShape(const std::string& line);

    void ProcessEvents();
    void HandleMousePress(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseMove(const sf::Event::MouseMoveEvent& mouse);
    void HandleKeyPress(const sf::Event::KeyEvent& key);
    void DeselectAllShapes();
};

