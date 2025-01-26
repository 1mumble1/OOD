#include "ReduceOutlineThicknessCommand.h"
#include "Toolbar.h"

void ReduceOutlineThicknessCommand::Execute() const
{
	m_toolbar->ReduceOutlineThickness();
}