#include "CreateRectangleCommand.h"
#include "Toolbar.h"

void CreateRectangleCommand::Execute() const
{
	m_toolBar->CreateRectangle();
}
