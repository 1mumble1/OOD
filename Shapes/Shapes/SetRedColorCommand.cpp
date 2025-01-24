#include "SetRedColorCommand.h"
#include "Toolbar.h"

void SetRedColorCommand::Execute() const
{
    m_toolbar->SetColor(sf::Color::Red);
}