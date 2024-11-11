#pragma once
#include "stdafx.h"

class CompositeShape : public IShape
{
public:
    static const std::string NAME;

    std::string ToString() const override;

    void Draw(sf::RenderWindow& window) const override;

    void AddShape(IShapePtr shape);
    void RemoveShape(IShapePtr shape);

    bool Contains(const sf::Vector2f& point) const override;
    void Move(const sf::Vector2f& offset) override;
    sf::Vector2f GetPosition() const override;

    std::vector<IShapePtr> GetShapes();
    void SetShapes(std::vector<IShapePtr> newShapes);

private:
    std::vector<IShapePtr> m_shapes;

    sf::Vector2f GetTopLeftPoint() const;
};

