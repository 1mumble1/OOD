#pragma once
#include "stdafx.h"

class IShape
{
public:
    virtual std::string ToString() const = 0;
    
    virtual void Draw(sf::RenderWindow& window) const = 0;

};

typedef std::shared_ptr<IShape> IShapePtr;