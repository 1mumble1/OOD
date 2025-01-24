#include "CreateCircleCommand.h"
#include "Toolbar.h"

void CreateCircleCommand::Execute() const
{
	m_toolBar->CreateCircle();
}
