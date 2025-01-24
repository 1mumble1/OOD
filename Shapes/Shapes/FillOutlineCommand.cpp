#include "FillOutlineCommand.h"
#include "Toolbar.h"

void FillOutlineCommand::Execute() const
{
	m_toolBar->FillOutline();
}
