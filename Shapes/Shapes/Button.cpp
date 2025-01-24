#include "Button.h"
#include "stdafx.h"

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_frame);
    window.draw(m_text);
}

bool Button::CursorInButton(sf::Vector2f cursorPos) const
{
    return m_frame.getGlobalBounds().contains(cursorPos);
}

void Button::PressButton()
{
    m_command->Execute();
}
