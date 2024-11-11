#pragma once
#include "ShapeMovableDecorator.h"
#include "stdafx.h"

class SimpleShapeMovableDecorator : public ShapeMovableDecorator
{
public:
	SimpleShapeMovableDecorator(IShapePtr&& shape)
		: ShapeMovableDecorator(std::move(shape))
	{}

    void Draw(sf::RenderWindow& window) const override;

    void Select() override;
    void Deselect() override;
    bool IsSelected() const override;
    void Move(const sf::Vector2f& offset) override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    sf::Vector2f GetSize() const override;

private:
    bool m_selected = false;
};

