#include "AddTriangleCommand.h"
#include "Toolbar.h"

void AddTriangleCommand::Execute() const
{
	m_toolbar->AddTriangle();
}
