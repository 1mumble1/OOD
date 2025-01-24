#include "FillShapeCommand.h"
#include "Toolbar.h"

void FillShapeCommand::Execute() const
{
	m_toolBar->FillShape();
}
