#include "ShapeHandler.h"
#include "ShapeCreator.h"
#include "ShapeMovableDecorator.h"
#include "SimpleShapeMovableDecorator.h"
#include "CompositeShape.h"
#include "CompositeShapeMovableDecorator.h"

void ShapeHandler::ReadShapesFromFile(const std::string& fileName)
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

        IShapePtr shape = ShapeCreator::CreateShape(line);
        if (shape != nullptr)
        {
            m_shapes.emplace_back(std::make_shared<SimpleShapeMovableDecorator>(std::move(shape)));
        }
    }
}

void ShapeHandler::SetMousePosition(sf::Vector2f mousePos)
{
    m_mousePos = mousePos;
}

sf::Vector2f ShapeHandler::GetMousePosition() const
{
    return m_mousePos;
}

void ShapeHandler::AddCircle()
{
    IShapePtr shape = ShapeCreator::CreateShape(CIRCLE_TEMPLATE);
    AddShape(shape);
}

void ShapeHandler::AddRectangle()
{
    IShapePtr shape = ShapeCreator::CreateShape(RECTANGLE_TEMPLATE);
    AddShape(shape);
}

void ShapeHandler::AddTriangle()
{
    IShapePtr shape = ShapeCreator::CreateShape(TRIANGLE_TEMPLATE);
    AddShape(shape);
}

void ShapeHandler::AddShape(IShapePtr shape)
{
    m_shapes.push_back(std::make_shared<SimpleShapeMovableDecorator>(std::move(shape)));
}

void ShapeHandler::AddOutlineThickness()
{
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->IsSelected())
        {
            shapePtr->AddOutlineThickness();
        }
    }
}

void ShapeHandler::ReduceOutlineThickness()
{
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->IsSelected())
        {
            shapePtr->ReduceOutlineThickness();
        }
    }
}

void ShapeHandler::FillColor(sf::Color color)
{
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->IsSelected())
        {
            shapePtr->SetFillColor(color);
        }
    }
}

void ShapeHandler::FillOutlineColor(sf::Color color)
{
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->IsSelected())
        {
            shapePtr->SetOutlineColor(color);
        }
    }
}

void ShapeHandler::DeselectAllShapes()
{
    for (auto& s : m_shapes)
    {
        auto sPtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(s);
        sPtr->Deselect();
    }
}

void ShapeHandler::SelectShape()
{
    bool isSelected = false;
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->Contains(m_mousePos))
        {
            DeselectAllShapes();
            shapePtr->Select();
            m_dragging = true;
            m_dragStart = m_mousePos;
            isSelected = true;
        }
    }
    if (!isSelected)
    {
        DeselectAllShapes();
    }
}

void ShapeHandler::SelectShapes()
{
    for (auto& shape : m_shapes)
    {
        auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
        if (shapePtr->Contains(m_mousePos))
        {
            shapePtr->Select();
            m_dragging = true;
            m_dragStart = m_mousePos;
        }
    }
}

void ShapeHandler::StopDragging()
{
    m_dragging = false;
}

void ShapeHandler::Move()
{
    if (m_dragging)
    {
        auto dragOffset = m_mousePos - m_dragStart;
        for (auto& shape : m_shapes)
        {
            auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
            if (shapePtr->IsSelected())
            {
                shapePtr->Move(dragOffset);
            }
        }
        m_dragStart = m_mousePos;
    }
}

void ShapeHandler::GroupShapes()
{
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

void ShapeHandler::UngroupShapes()
{
    std::vector<IShapePtr> newShapes;
    for (auto& shape : m_shapes)
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
    m_shapes = newShapes;
}

void ShapeHandler::SetShapes(std::vector<IShapePtr> newShapes)
{
    m_shapes = newShapes;
}

std::vector<IShapePtr> ShapeHandler::GetShapes() const
{
    return m_shapes;
}

