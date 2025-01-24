#include "CreateTriangleCommand.h"
#include "Toolbar.h"

void CreateTriangleCommand::Execute() const
{
	m_toolBar->CreateTriangle();
}
