#include "AddRectangleCommand.h"
#include "Toolbar.h"

void AddRectangleCommand::Execute() const
{
	m_toolbar->AddRectangle();
}
