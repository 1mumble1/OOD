#include "DragAndDropCommand.h"
#include "Toolbar.h"

void DragAndDropCommand::Execute() const
{
	m_toolBar->DragAndDrop();
}
