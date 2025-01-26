#include "DragAndDropCommand.h"
#include "Toolbar.h"

void DragAndDropCommand::Execute() const
{
	m_toolbar->DragAndDrop();
}
