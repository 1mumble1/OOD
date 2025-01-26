#pragma once
#include "stdafx.h"

class CompositeShape : public IShape
{
public:
	static const std::string NAME;

	std::string ToString() const override;

	void Draw(sf::RenderWindow& window) const override;

	std::string ToStringShapes() const;
	void AddShape(IShapePtr shape);
	void RemoveShape(IShapePtr shape);

	std::vector<IShapePtr> GetShapes();
	void SetShapes(std::vector<IShapePtr> newShapes);

	void Move(const sf::Vector2f& offset) override;
	bool Contains(const sf::Vector2f& point) const override;
	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetSize() const override;

	void AddOutlineThickness() override;
	void ReduceOutlineThickness() override;
	void SetFillColor(sf::Color color) override;
	void SetOutlineColor(sf::Color color) override;
	sf::Color GetFillColor() const override;
	sf::Color GetOutlineColor() const override;

private:
	std::vector<IShapePtr> m_shapes;
};

