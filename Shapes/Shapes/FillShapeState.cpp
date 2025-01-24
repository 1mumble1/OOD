#include "FillShapeState.h"
#include "DragAndDropState.h"
#include "FillOutlineState.h"
#include "Toolbar.h"

void FillShapeState::DragAndDrop(Toolbar* toolbar) const
{
	toolbar->SetState(new DragAndDropState());
}

void FillShapeState::FillShape(Toolbar* toolbar) const
{
}

void FillShapeState::FillOutline(Toolbar* toolbar) const
{
	toolbar->SetState(new FillOutlineState());
}
