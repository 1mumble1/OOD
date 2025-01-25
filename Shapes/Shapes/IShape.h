#pragma once
#include "stdafx.h"

class IShape
{
public:
    virtual std::string ToString() const = 0;
    
    virtual void Draw(sf::RenderWindow& window) const = 0;

    virtual void Move(const sf::Vector2f& offset) = 0;
    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual sf::Vector2f GetPosition() const = 0;
    virtual sf::Vector2f GetSize() const = 0;
    virtual void SetFillColor(const sf::Color newColor) = 0;
    virtual void SetOutlineColor(const sf::Color newColor) = 0;
    virtual void AddOutlineThickness() = 0;
    virtual void ReduceOutlineThickness() = 0;
    virtual sf::Color GetFillColor() const = 0;
    virtual sf::Color GetOutlineColor() const = 0;
    virtual float GetThickness() const = 0;

    virtual std::shared_ptr<IShape> Clone() const = 0;
};

typedef std::shared_ptr<IShape> IShapePtr;