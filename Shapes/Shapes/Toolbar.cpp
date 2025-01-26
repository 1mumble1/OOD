#include "Toolbar.h"
#include "FillColorState.h"
#include "FillOutlineColorState.h"

void Toolbar::AddCircle()
{
	m_handler->AddCircle();
}

void Toolbar::AddRectangle()
{
	m_handler->AddRectangle();
}

void Toolbar::AddTriangle()
{
	m_handler->AddTriangle();
}

void Toolbar::DragAndDrop()
{
	m_state = std::make_shared<DragAndDropState>();
}

void Toolbar::FillColor()
{
	m_state = std::make_shared<FillColorState>();
}

void Toolbar::FillOutlineColor()
{
	m_state = std::make_shared<FillOutlineColorState>();
}

void Toolbar::ApplySettingColor()
{
	if (std::dynamic_pointer_cast<FillColorState>(m_state))
	{
		m_handler->FillColor(m_color);
	}
	else if (std::dynamic_pointer_cast<FillOutlineColorState>(m_state))
	{
		m_handler->FillOutlineColor(m_color);
	}
}

void Toolbar::SetColor(sf::Color newColor)
{
	m_color = newColor;
}

sf::Color Toolbar::GetColor() const
{
	return m_color;
}

void Toolbar::AddOutlineThickness()
{
	m_handler->AddOutlineThickness();
}

void Toolbar::ReduceOutlineThickness()
{
	m_handler->ReduceOutlineThickness();
}

bool Toolbar::TryPressToolButton(sf::Vector2f mousePos)
{
	for (auto& button : m_buttons)
	{
		if (button->Contains(mousePos))
		{
			button->PressButton();
			return true;
		}
	}
	return false;
}

void Toolbar::Draw() const
{
	for (auto& button : m_buttons)
	{
		button->Draw(m_window);
	}
}

std::shared_ptr<IState> Toolbar::GetState() const
{
	return m_state;
}
