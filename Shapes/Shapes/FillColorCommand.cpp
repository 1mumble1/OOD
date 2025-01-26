#include "FillColorCommand.h"
#include "Toolbar.h"

void FillColorCommand::Execute() const
{
	m_toolbar->FillColor();
}