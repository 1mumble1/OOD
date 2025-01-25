#include "ShapeHandler.h"
#include "ShapeCreator.h"
#include "ShapeMovableDecorator.h"
#include "SimpleShapeMovableDecorator.h"

void ShapeHandler::AddShape(IShapePtr& shape)
{
	shape = std::make_shared<SimpleShapeMovableDecorator>(std::move(shape));
	m_shapes.push_back(shape);
}

void ShapeHandler::CreateCircle()
{
	IShapePtr shape = ShapeCreator::CreateShape(CIRCLE_TEMPLATE);
	AddShape(shape);
}

void ShapeHandler::CreateRectangle()
{
	IShapePtr shape = ShapeCreator::CreateShape(RECTANGLE_TEMPLATE);
	AddShape(shape);
}

void ShapeHandler::CreateTriangle()
{
	IShapePtr shape = ShapeCreator::CreateShape(TRIANGLE_TEMPLATE);
	AddShape(shape);
}

std::vector<IShapePtr> ShapeHandler::GetShapes() const
{
	return m_shapes;
}

void ShapeHandler::SetShapes(std::vector<IShapePtr> shapes)
{
	m_shapes = shapes;
}

void ShapeHandler::SetFillColorForSelectedShapes(const sf::Color& color)
{
	for (const auto& shape : m_shapes)
	{
		auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
		if (shapePtr->IsSelected())
		{
			shapePtr->SetFillColor(color);
		}
	}
}

void ShapeHandler::SetOutlineColorForSelectedShapes(const sf::Color& color)
{
	for (const auto& shape : m_shapes)
	{
		auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
		if (shapePtr->IsSelected())
		{
			shapePtr->SetOutlineColor(color);
		}
	}
}

void ShapeHandler::AddOutlineThicknessForSelectedShapes()
{
	for (const auto& shape : m_shapes)
	{
		auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
		if (shapePtr->IsSelected())
		{
			shapePtr->AddOutlineThickness();
		}
	}
}

void ShapeHandler::ReduceOutlineThicknessForSelectedShapes()
{
	for (const auto& shape : m_shapes)
	{
		auto shapePtr = std::dynamic_pointer_cast<ShapeMovableDecorator>(shape);
		if (shapePtr->IsSelected())
		{
			shapePtr->ReduceOutlineThickness();
		}
	}
}
