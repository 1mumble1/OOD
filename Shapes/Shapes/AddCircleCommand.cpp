#include "AddCircleCommand.h"
#include "Toolbar.h"

void AddCircleCommand::Execute() const
{
	m_toolbar->AddCircle();
}
