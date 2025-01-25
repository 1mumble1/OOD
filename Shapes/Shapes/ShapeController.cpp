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
#include "DragAndDropState.h"

ShapeController& ShapeController::GetInstance()
{
    static ShapeController instance;
    return instance;
}

void ShapeController::ReadShapes(const std::string& fileName)
{
    std::ifstream input(fileName);
    std::vector<IShapePtr> shapes;
    if (!input.is_open())
    {
        std::cout << ERROR_OPEN_FILE << std::endl;
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
            shapes.emplace_back(shape);
        }
    }

    m_handler->SetShapes(shapes);
    m_history->UpdateHistory(std::make_shared<ShapeMemento>(shapes));
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

void ShapeController::DeselectAllShapes()
{
    for (auto& s : m_handler->GetShapes())
    {
        auto sPtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(s);
        sPtr->Deselect();
    }
}

void ShapeController::HandleMousePress(const sf::Event::MouseButtonEvent& mouse)
{
    sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(mouse.x, mouse.y));
    bool isSelected = false;
    if (mouse.button == sf::Mouse::Left)
    {
        m_toolBar->SetCursorPosition(mousePos);
        m_toolBar->PressToolButton();
        SaveChanges();

        if (typeid(*m_toolBar->GetState()) == typeid(DragAndDropState))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {

                for (auto& shape : m_handler->GetShapes())
                {
                    auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
                    if (shapePtr->Contains(mousePos))
                    {
                        shapePtr->Select();
                        m_dragging = true;
                        m_dragStart = mousePos;
                    }
                }
            }
            else
            {
                for (auto& shape : m_handler->GetShapes())
                {
                    auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
                    if (shapePtr->Contains(mousePos))
                    {
                        DeselectAllShapes();
                        shapePtr->Select();
                        m_dragging = true;
                        m_dragStart = mousePos;
                        isSelected = true;
                    }
                }
                if (!isSelected)
                {
                    DeselectAllShapes();
                }
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
        auto dragOffset = mousePos - m_dragStart;
        for (auto& shape : m_handler->GetShapes())
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
            if (shapePtr->IsSelected())
            {
                shapePtr->Move(dragOffset);
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
        auto shapes = m_handler->GetShapes();
        for (auto it = shapes.begin(); it != shapes.end();)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(*it);

            if (shapePtr->IsSelected())
            {
                compositeShape.AddShape(*it);
                it = shapes.erase(it);
            }
            else
            {
                ++it;
            }
        }
        shapes.push_back(std::make_shared<CompositeShapeMovableDecorator>(std::make_shared<CompositeShape>(compositeShape)));
        m_handler->SetShapes(shapes);
        SaveChanges();
    }
    else if (key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        std::vector<IShapePtr> shapes = m_handler->GetShapes();
        std::vector<IShapePtr> newShapes;
        for (auto& shape : shapes)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
            if (shapePtr->IsSelected() && shapePtr->ToString() == CompositeShape::NAME)
            {
                auto compositeShape = std::dynamic_pointer_cast<CompositeShapeMovableDecorator>(shape);
                for (auto& s : compositeShape->GetShapes())
                {
                    newShapes.push_back(s);
                }
            }
            else
            {
                newShapes.push_back(shape);
            }
        }
        m_handler->SetShapes(newShapes);
        SaveChanges();
    }
    else if (key.code == sf::Keyboard::Z && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        auto previousState = m_history->Undo();
        if (previousState != nullptr)
        {
            m_handler->SetShapes(previousState->GetState());
        }
    }
}

void ShapeController::DrawShapes()
{
    m_window.setVerticalSyncEnabled(true);

    std::vector<IShapePtr> movableShapes;
    for (auto& shape : m_handler->GetShapes())
    {
        movableShapes.push_back(std::make_shared<SimpleShapeMovableDecorator>(std::move(shape)));
    }
    m_handler->SetShapes(movableShapes);
 
    while (m_window.isOpen())
    {
        sf::Event event{};
        ProcessEvents();

        m_window.clear(sf::Color::White);

        for (auto const& shape : m_handler->GetShapes())
        {
            shape->Draw(m_window);
        }

        m_toolBar->Draw();

        m_window.display();
    }
}

void ShapeController::PrintShapesInfo(const std::string& fileName)
{
    std::ofstream output(fileName);
    if (!output.is_open())
    {
        std::cout << ERROR_OPEN_FILE;
        return;
    }

    for (auto& shape : m_handler->GetShapes())
    {
        IShapePtr currentShape = shape;

        while (auto movableDecorator = std::dynamic_pointer_cast<ShapeMovableDecorator>(currentShape))
        {
            currentShape = movableDecorator->GetOriginalShape();
        }

        if (currentShape->ToString() == CTriangleShape::NAME)
        {
            auto mathShape = std::make_shared<CTriangleMathDecorator>(std::move(currentShape));
            output << mathShape->ToString() << std::endl;
        }
        else if (currentShape->ToString() == CRectangleShape::NAME)
        {
            auto mathShape = std::make_shared<CRectangleMathDecorator>(std::move(currentShape));
            
        }
        else if (currentShape->ToString() == CCircleShape::NAME)
        {
            auto mathShape = std::make_shared<CCircleMathDecorator>(std::move(currentShape));
            output << mathShape->ToString() << std::endl;
        }
        else
        {
            output << currentShape->ToString() << std::endl;
        }
    }

    output.close();
}

void ShapeController::SaveChanges()
{
    std::vector<IShapePtr> clonedShapes;
    for (const auto& shape : m_handler->GetShapes())
    {
        //auto movableShape = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        
        clonedShapes.push_back(shape->Clone());
    }
    m_history->UpdateHistory(std::make_shared<ShapeMemento>(clonedShapes));
}
