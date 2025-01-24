#include "SetBlueColorCommand.h"
#include "Toolbar.h"

void SetBlueColorCommand::Execute() const
{
	m_toolbar->SetColor(sf::Color::Blue);
}