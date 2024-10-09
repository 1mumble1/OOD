#pragma once
#include "stdafx.h"

class IShape
{
public:
    //virtual float GetArea() const = 0;
    //virtual float GetPerimeter() const = 0;

    virtual std::string ToString() const = 0;
    
    virtual void Draw(sf::RenderWindow& window) const = 0;

};

typedef std::shared_ptr<IShape> IShapePtr;