#include "ShapeController.h"
#include "stdafx.h"
#include "ShapeCreator.h"
#include "ShapeDecorator.h"
#include "ColorsGenerator.h"
#include "CTriangleMathDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CCircleMathDecorator.h"

void ShapeController::ReadShapes(const std::string& fileName)
{
    std::ifstream input(fileName);
    if (!input.is_open())
    {
        std::cout << "Ошибка при окрытии файла";
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



void ShapeController::DrawShapes()
{
    m_window.setVerticalSyncEnabled(true);
 
    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

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
        std::cout << "Ошибка при окрытии файла";
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