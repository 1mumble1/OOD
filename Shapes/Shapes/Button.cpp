#include "Button.h"

void Button::Draw(sf::RenderWindow& window) const
{
	window.draw(m_frame);
	window.draw(m_text);
}

void Button::PressButton()
{
	m_command->Execute();
}

bool Button::Contains(sf::Vector2f pos) const
{
	return m_frame.getGlobalBounds().contains(pos);
}
