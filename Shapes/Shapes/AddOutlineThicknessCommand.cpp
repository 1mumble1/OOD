#include "AddOutlineThicknessCommand.h"
#include "Toolbar.h"

void AddOutlineThicknessCommand::Execute() const
{
	m_toolbar->AddOutlineThickness();
}
