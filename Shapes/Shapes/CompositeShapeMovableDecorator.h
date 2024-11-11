#pragma once
#include "stdafx.h"
#include "ShapeMovableDecorator.h"
#include "CompositeShape.h"

class CompositeShapeMovableDecorator : ShapeMovableDecorator
{
public:
    CompositeShapeMovableDecorator(IShapePtr&& shape)
        : ShapeMovableDecorator(std::move(shape))
    {
        std::vector<IShapePtr> shapes = std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes();
        for (auto& shape : std::dynamic_pointer_cast<CompositeShape>(m_shape)->GetShapes())
        {
            shape = std::make_shared<ShapeMovableDecorator>(shape);
        }

        std::dynamic_pointer_cast<CompositeShape>(m_shape)->SetShapes(shapes);
    }

    void Select() override;
    void Deselect() override;
    bool IsSelected() const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Move(const sf::Vector2f& offset) override;
    sf::Vector2f GetPosition() const override;
};

