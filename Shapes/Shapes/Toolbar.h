#pragma once
#include "stdafx.h"
#include "Button.h"
#include "AddCircleCommand.h"
#include "AddRectangleCommand.h"
#include "AddTriangleCommand.h"
#include "DragAndDropCommand.h"
#include "FillColorCommand.h"
#include "FillOutlineColorCommand.h"
#include "SetRedColorCommand.h"
#include "SetBlueColorCommand.h"
#include "SetGreenColorCommand.h"
#include "AddOutlineThicknessCommand.h"
#include "ReduceOutlineThicknessCommand.h"
#include "IState.h"
#include "ShapeHandler.h"
#include "DragAndDropState.h"

class Toolbar
{
public:
	Toolbar(sf::RenderWindow& window, ShapeHandler* handler)
		: m_window(window)
		, m_handler(handler)
	{
		m_buttons.push_back(std::make_shared<Button>(new AddCircleCommand(this), POSITION_OF_CREATE_CIRCLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_CIRCLE_BUTTON, FONT_SIZE));
		m_buttons.push_back(std::make_shared<Button>(new AddRectangleCommand(this), POSITION_OF_CREATE_RECTANGLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_RECTANGLE_BUTTON, FONT_SIZE));
		m_buttons.push_back(std::make_shared<Button>(new AddTriangleCommand(this), POSITION_OF_CREATE_TRIANGLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_TRIANGLE_BUTTON, FONT_SIZE));

		m_buttons.push_back(std::make_shared<Button>(new DragAndDropCommand(this), POSITION_OF_DRAG_AND_DROP_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_DRAG_AND_DROP_BUTTON, FONT_SIZE));
		m_buttons.push_back(std::make_shared<Button>(new FillColorCommand(this), POSITION_OF_FILL_COLOR_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_FILL_COLOR_BUTTON, FONT_SIZE));
		m_buttons.push_back(std::make_shared<Button>(new FillOutlineColorCommand(this), POSITION_OF_FILL_OUTLINE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_FILL_OUTLINE_BUTTON, FONT_SIZE));

		m_buttons.push_back(std::make_shared<Button>(new SetRedColorCommand(this), POSITION_OF_SET_RED_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Red));
		m_buttons.push_back(std::make_shared<Button>(new SetGreenColorCommand(this), POSITION_OF_SET_GREEN_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Green));
		m_buttons.push_back(std::make_shared<Button>(new SetBlueColorCommand(this), POSITION_OF_SET_BLUE_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Blue));

		m_buttons.push_back(std::make_shared<Button>(new AddOutlineThicknessCommand(this), POSITION_OF_ADD_THICKNESS_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Black, TEXT_OF_ADD_THICKNESS_BUTTON, FONT_SIZE));
		m_buttons.push_back(std::make_shared<Button>(new ReduceOutlineThicknessCommand(this), POSITION_OF_REDUCE_THICKNESS_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Black, TEXT_OF_REDUCE_THICKNESS_BUTTON, FONT_SIZE));
	}

	void AddCircle();
	void AddRectangle();
	void AddTriangle();

	void DragAndDrop();
	void FillColor();
	void FillOutlineColor();
	void ApplySettingColor();

	void SetColor(sf::Color newColor);
	sf::Color GetColor() const;
	
	void AddOutlineThickness();
	void ReduceOutlineThickness();

	bool TryPressToolButton(sf::Vector2f mousePos);

	void Draw() const;

	std::shared_ptr<IState> GetState() const;

private:
	std::vector<std::shared_ptr<Button>> m_buttons;
	sf::RenderWindow& m_window;
	ShapeHandler* m_handler;

	std::shared_ptr<IState> m_state = std::make_shared<DragAndDropState>();
	sf::Color m_color = sf::Color::Red;
};

