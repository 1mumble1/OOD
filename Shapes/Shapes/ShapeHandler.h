#pragma once
#include "stdafx.h"

class ShapeHandler
{
public:
	ShapeHandler(sf::RenderWindow& window)
		: m_window(window)
	{}

	void CreateCircle();
	void CreateRectangle();
	void CreateTriangle();

	std::vector<IShapePtr> GetShapes() const;
	void SetShapes(std::vector<IShapePtr> shapes);

	void SetFillColor(const sf::Color& color);
	void SetOutlineColor(const sf::Color& color);
	void AddOutlineThickness();
	void ReduceOutlineThickness();

private:
	void AddShape(IShapePtr& shape);

	std::vector<IShapePtr> m_shapes;
	sf::RenderWindow& m_window;
};

