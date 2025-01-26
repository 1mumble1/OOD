#pragma once
#include "stdafx.h"
#include "CompositeShape.h"
#include "ShapeHandler.h"
#include "Toolbar.h"

class Application
{
public:
    Application(const Application&) = delete;
    void operator=(const Application&) = delete;
    static Application& GetInstance();

    void ReadShapes(const std::string& fileName);

    void DrawShapes();

private:
    Application()
    {
        m_handler = new ShapeHandler(m_window);
        m_toolbar = new Toolbar(m_window, m_handler);
        m_state = m_toolbar->GetState();
    };

    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);
    sf::Vector2f m_dragStart;
    bool m_dragging = false;
    ShapeHandler* m_handler;
    Toolbar* m_toolbar;
    std::shared_ptr<IState> m_state;


    void ProcessEvents();
    void HandleMousePress(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse);
    void HandleMouseMove(const sf::Event::MouseMoveEvent& mouse);
    void HandleKeyPress(const sf::Event::KeyEvent& key);
};

