#pragma once
#include "stdafx.h"
#include "ICommand.h"

class Button
{
public:
	Button(
		ICommand* command,
		sf::Vector2f buttonPos,
		sf::Vector2f buttonSize,
		sf::Color buttonColor = sf::Color::Black,
		std::string buttonText = "",
		int fontSize = 0
		)
		: m_command(command)
	{
		m_frame = sf::RectangleShape(buttonSize);
		m_frame.setPosition(buttonPos);
		m_frame.setFillColor(buttonColor);

		if (m_font.loadFromFile(FONT_FILE_NAME))
		{
			m_text.setFont(m_font);
			m_text.setString(buttonText);
			m_text.setFillColor(sf::Color::White);
			m_text.setCharacterSize(fontSize);
			m_text.setPosition(buttonPos);
		}
	}

	void Draw(sf::RenderWindow& window) const;
	void PressButton();
	bool Contains(sf::Vector2f pos) const;

private:
	sf::RectangleShape m_frame;
	sf::Text m_text;
	sf::Font m_font;
	ICommand* m_command;
};

