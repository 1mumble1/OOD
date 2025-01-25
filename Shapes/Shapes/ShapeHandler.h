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

	void SetFillColorForSelectedShapes(const sf::Color& color);
	void SetOutlineColorForSelectedShapes(const sf::Color& color);
	void AddOutlineThicknessForSelectedShapes();
	void ReduceOutlineThicknessForSelectedShapes();

private:
	void AddShape(IShapePtr& shape);

	std::vector<IShapePtr> m_shapes;
	sf::RenderWindow& m_window;
};

