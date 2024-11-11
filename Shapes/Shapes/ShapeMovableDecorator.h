#pragma once
#include "stdafx.h"

class ShapeMovableDecorator : public IShape
{
public:
    ShapeMovableDecorator(IShapePtr&& shape)
        : m_shape(std::move(shape))
    {}

    std::string ToString() const override;
    void Draw(sf::RenderWindow& window) const override;

    virtual void Select();
    virtual void Deselect();
    virtual bool IsSelected() const;

    virtual bool Contains(const sf::Vector2f& point) const override;
    virtual void Move(const sf::Vector2f& offset) override;
    virtual sf::Vector2f GetPosition() const override;

protected:
    IShapePtr m_shape;

private:
    bool m_selected = false;
};

