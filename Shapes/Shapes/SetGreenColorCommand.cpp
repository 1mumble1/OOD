#include "SetGreenColorCommand.h"
#include "Toolbar.h"

void SetGreenColorCommand::Execute() const
{
	m_toolbar->SetColor(sf::Color::Green);
	m_toolbar->ApplySettingColor();
}