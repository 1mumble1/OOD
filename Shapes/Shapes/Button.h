#pragma once
#include "ICommand.h"
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(
        ICommand* command,
        sf::Vector2f position,
        sf::Vector2f sizeOfFrame,
        sf::Color buttonColor = sf::Color::Black,
        std::string text = "",
        int fontSize = 0,
        sf::Color textColor = sf::Color::White
    )
        : m_command(command)
    {
        m_frame.setPosition(position);
        m_frame.setSize(sizeOfFrame);
        m_frame.setFillColor(buttonColor);

        if (m_font.loadFromFile(FONT_FILE_NAME))
        {
            m_text.setFont(m_font);
            m_text.setString(text);
            m_text.setFillColor(textColor);
            m_text.setCharacterSize(fontSize);
            m_text.setPosition(position);
        }
    }

    void Draw(sf::RenderWindow& window);
    bool CursorInButton(sf::Vector2f cursorPos) const;
    void PressButton();

private:
    sf::RectangleShape m_frame;
    sf::Text m_text;
    sf::Font m_font;
    ICommand* m_command;
};