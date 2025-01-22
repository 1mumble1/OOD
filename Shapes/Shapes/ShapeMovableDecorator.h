#pragma once
#include "stdafx.h"

class ShapeMovableDecorator : public IShape
{
public:
    ShapeMovableDecorator(IShapePtr&& shape)
        : m_shape(std::move(shape))
    {}

    IShapePtr GetOriginalShape() const { return m_shape; }

    std::string ToString() const override;

    virtual void Draw(sf::RenderWindow& window) const override = 0;

    virtual void Select() = 0;
    virtual void Deselect() = 0;
    virtual bool IsSelected() const = 0;
    virtual void Move(const sf::Vector2f& offset) override = 0;
    virtual bool Contains(const sf::Vector2f& point) const override = 0;
    virtual sf::Vector2f GetPosition() const override = 0;
    virtual sf::Vector2f GetSize() const override = 0;

protected:
    IShapePtr m_shape;
};

