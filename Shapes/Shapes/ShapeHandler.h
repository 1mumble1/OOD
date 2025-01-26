#pragma once
#include "stdafx.h"

class ShapeHandler
{
public:
	ShapeHandler(sf::RenderWindow& window)
		: m_window(window)
	{}

	void ReadShapesFromFile(const std::string& fileName);

	void SetMousePosition(sf::Vector2f mousePos);
	sf::Vector2f GetMousePosition() const;

	void AddCircle();
	void AddRectangle();
	void AddTriangle();
	void AddOutlineThickness();
	void ReduceOutlineThickness();
	void FillColor(sf::Color color);
	void FillOutlineColor(sf::Color color);

	void SelectShape();
	void SelectShapes();
	void StopDragging();
	void Move();
	void GroupShapes();
	void UngroupShapes();

	std::vector<IShapePtr> GetShapes() const;
	void SetShapes(std::vector<IShapePtr> newShapes);

private:
	std::vector<IShapePtr> m_shapes;
	sf::RenderWindow& m_window;
	bool m_dragging = false;
	sf::Vector2f m_dragStart;
	sf::Vector2f m_mousePos;

	void AddShape(IShapePtr shape);

	void DeselectAllShapes();
};

