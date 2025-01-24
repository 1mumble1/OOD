#pragma once
#include "stdafx.h"
#include "ShapeHandler.h"
#include "Button.h"
#include "CreateCircleCommand.h"
#include "CreateRectangleCommand.h"
#include "CreateTriangleCommand.h"
#include "DragAndDropCommand.h"
#include "FillShapeCommand.h"
#include "FillOutlineCommand.h"
#include "IState.h"
#include "ICommand.h"
#include "SetRedColorCommand.h"
#include "SetGreenColorCommand.h"
#include "SetBlueColorCommand.h"
#include "FillShapeState.h"
#include "FillOutlineState.h"
#include "AddOutlineThicknessCommand.h"
#include "ReduceOutlineThicknessCommand.h"
#include "DragAndDropState.h"

class Button;
class IState;

class Toolbar
{
public:
	Toolbar(sf::RenderWindow& window, ShapeHandler* handler)
		: m_window(window)
		, m_handler(handler)
	{ 
		m_buttons.push_back(new Button(new CreateCircleCommand(this), POSITION_OF_CREATE_CIRCLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_CIRCLE_BUTTON, FONT_SIZE));
		m_buttons.push_back(new Button(new CreateRectangleCommand(this), POSITION_OF_CREATE_RECTANGLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_RECTANGLE_BUTTON, FONT_SIZE));
		m_buttons.push_back(new Button(new CreateTriangleCommand(this), POSITION_OF_CREATE_TRIANGLE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_CREATE_TRIANGLE_BUTTON, FONT_SIZE));

		m_buttons.push_back(new Button(new DragAndDropCommand(this), POSITION_OF_DRAG_AND_DROP_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_DRAG_AND_DROP_BUTTON, FONT_SIZE));
		m_buttons.push_back(new Button(new FillShapeCommand(this), POSITION_OF_FILL_COLOR_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_FILL_COLOR_BUTTON, FONT_SIZE));
		m_buttons.push_back(new Button(new FillOutlineCommand(this), POSITION_OF_FILL_OUTLINE_BUTTON, SIZE_OF_BIG_BUTTON, sf::Color::Black, TEXT_OF_FILL_OUTLINE_BUTTON, FONT_SIZE));

		m_buttons.push_back(new Button(new SetRedColorCommand(this), POSITION_OF_SET_RED_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Red));
		m_buttons.push_back(new Button(new SetGreenColorCommand(this), POSITION_OF_SET_GREEN_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Green));
		m_buttons.push_back(new Button(new SetBlueColorCommand(this), POSITION_OF_SET_BLUE_COLOR_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Blue));

		m_buttons.push_back(new Button(new AddOutlineThicknessCommand(this), POSITION_OF_ADD_THICKNESS_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Black, TEXT_OF_ADD_THICKNESS_BUTTON, FONT_SIZE));
		m_buttons.push_back(new Button(new ReduceOutlineThicknessCommand(this), POSITION_OF_REDUCE_THICKNESS_BUTTON, SIZE_OF_SMALL_BUTTON, sf::Color::Black, TEXT_OF_REDUCE_THICKNESS_BUTTON, FONT_SIZE));

		m_state = new DragAndDropState();
	}

	void SetCursorPosition(const sf::Vector2f& position);
	bool PressToolButton() const;

	void CreateRectangle();
	void CreateTriangle();
	void CreateCircle();

	void DragAndDrop();
	void FillShape();
	void FillOutline();

	void AddOutlineThickness();
	void ReduceOutlineThickness();

	void SetColor(const sf::Color& newColor);

	void SetState(IState* state);
	IState* GetState() const;

	void Draw();

private:
	std::vector<Button*> m_buttons;
	sf::RenderWindow& m_window;
	ShapeHandler* m_handler;

	IState* m_state;
	sf::Vector2f m_cursorPosition;

	sf::Color m_color = sf::Color::Red;
};

