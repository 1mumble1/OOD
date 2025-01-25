#include "Toolbar.h"

void Toolbar::SetCursorPosition(const sf::Vector2f& position)
{
	m_cursorPosition = position;
}

bool Toolbar::PressToolButton() const
{
	for (auto button : m_buttons)
	{
		if (button->CursorInButton(m_cursorPosition))
		{
			button->PressButton();
			return true;
		}
	}

	return false;
}

void Toolbar::CreateRectangle()
{
	m_handler->CreateRectangle();
}

void Toolbar::CreateTriangle()
{
	m_handler->CreateTriangle();
}

void Toolbar::CreateCircle()
{
	m_handler->CreateCircle();
}

void Toolbar::DragAndDrop()
{
	if (m_state)
	{
		m_state->DragAndDrop(this);
	}
}

void Toolbar::FillShape()
{
	if (m_state)
	{
		m_state->FillShape(this);
	}
}

void Toolbar::FillOutline()
{
	if (m_state)
	{
		m_state->FillOutline(this);
	}
}

void Toolbar::AddOutlineThickness()
{
	m_handler->AddOutlineThicknessForSelectedShapes();
}

void Toolbar::ReduceOutlineThickness()
{
	m_handler->ReduceOutlineThicknessForSelectedShapes();
}

void Toolbar::SetColor(const sf::Color& newColor)
{
	m_color = newColor;
	if (typeid(*m_state) == typeid(FillShapeState))
	{
		m_handler->SetFillColorForSelectedShapes(m_color);
	}
	else if (typeid(*m_state) == typeid(FillOutlineState))
	{
		m_handler->SetOutlineColorForSelectedShapes(m_color);
	}
}

void Toolbar::SetState(IState* state)
{
	m_state = state;
}

IState* Toolbar::GetState() const
{
	return m_state;
}

void Toolbar::Draw()
{
	for (auto button : m_buttons)
	{
		button->Draw(m_window);
	}
}

