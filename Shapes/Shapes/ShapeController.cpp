#include "ShapeController.h"
#include "stdafx.h"
#include "ShapeCreator.h"
#include "ShapeMathDecorator.h"
#include "ColorsGenerator.h"
#include "CTriangleMathDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CCircleMathDecorator.h"
#include "ShapeMovableDecorator.h"
#include "SimpleShapeMovableDecorator.h"
#include "CompositeShapeMovableDecorator.h"

void ShapeController::ReadShapes(const std::string& fileName)
{
    std::ifstream input(fileName);
    if (!input.is_open())
    {
        std::cout << "Ошибка при открытии файла";
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        if (line.empty())
        {
            continue;
        }

        IShapePtr shape = ConstructShape(line);
        if (shape != nullptr)
        {
            m_shapes.emplace_back(shape);
        }
    }
}

IShapePtr ShapeController::ConstructShape(const std::string& line)
{
    IShapePtr shape = ShapeCreator::CreateShape(line);
    return shape;
}

void ShapeController::ProcessEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            HandleMousePress(event.mouseButton);
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            HandleMouseRelease(event.mouseButton);
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            HandleMouseMove(event.mouseMove);
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            HandleKeyPress(event.key);
        }
    }
}

void ShapeController::HandleMousePress(const sf::Event::MouseButtonEvent& mouse)
{
    sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(mouse.x, mouse.y));
    if (mouse.button == sf::Mouse::Left)
    {
        for (auto& shape : m_shapes)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
            if (shapePtr->Contains(mousePos))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    shapePtr->Select();
                }
                else
                {
                    for (auto& s : m_shapes)
                    {
                        auto sPtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(s);
                        sPtr->Deselect();
                    }
                    shapePtr->Select();
                }
                m_dragging = true;
                m_dragStart = mousePos;
                break;
            }
        }
    }
}

void ShapeController::HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse)
{
    if (mouse.button == sf::Mouse::Left)
    {
        m_dragging = false;
    }
}

void ShapeController::HandleMouseMove(const sf::Event::MouseMoveEvent& mouse)
{
    if (m_dragging)
    {
        sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(mouse.x, mouse.y));
        m_dragOffset = mousePos - m_dragStart;
        for (auto& shape : m_shapes)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
            if (shapePtr->IsSelected())
            {
                shapePtr->Move(m_dragOffset);
            }
        }
        m_dragStart = mousePos;
    }
}

void ShapeController::HandleKeyPress(const sf::Event::KeyEvent& key)
{
    if (key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        // Group selected shapes
        CompositeShape compositeShape;
        for (auto it = m_shapes.begin(); it != m_shapes.end();)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(*it);

            if (shapePtr->IsSelected())
            {
                compositeShape.AddShape(*it);
                it = m_shapes.erase(it);
            }
            else
            {
                ++it;
            }
        }
        m_shapes.push_back(std::make_shared<CompositeShapeMovableDecorator>(std::make_shared<CompositeShape>(compositeShape)));
    }
    else if (key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        // Ungroup selected shapes
        for (auto it = m_shapes.begin(); it != m_shapes.end();)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(*it);

            if (shapePtr->IsSelected() && dynamic_cast<CompositeShape*>(it->get()))
            {
                CompositeShape* compositeShape = dynamic_cast<CompositeShape*>(it->get());
                for (auto& shape : compositeShape->GetShapes())
                {
                    m_shapes.push_back(std::make_shared<SimpleShapeMovableDecorator>(std::move(shape)));
                }
                it = m_shapes.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

void ShapeController::DrawShapes()
{
    m_window.setVerticalSyncEnabled(true);

    for (auto& shape : m_shapes)
    {
        shape = std::make_shared<SimpleShapeMovableDecorator>(std::move(shape));
    }
 
    while (m_window.isOpen())
    {
        sf::Event event{};
        ProcessEvents();

        m_window.clear(sf::Color::White);

        for (auto const& shape : m_shapes)
        {
            shape->Draw(m_window);
        }

        m_window.display();
    }
}

void ShapeController::PrintShapesInfo(const std::string& fileName)
{
    std::ofstream output(fileName);
    if (!output.is_open())
    {
        std::cout << "Ошибка при открытии файла";
        return;
    }

    for (auto& shape : m_shapes)
    {
        if (shape->ToString() == CTriangleShape::NAME)
        {
            shape = std::make_shared<CTriangleMathDecorator>(std::move(shape));
        }
        else if (shape->ToString() == CRectangleShape::NAME)
        {
            shape = std::make_shared<CRectangleMathDecorator>(std::move(shape));
        }
        else if (shape->ToString() == CCircleShape::NAME)
        {
            shape = std::make_shared<CCircleMathDecorator>(std::move(shape));
        }
    }

    for (auto const& shape : m_shapes)
    {
        output << shape->ToString() << std::endl;
    }

    output.close();
}