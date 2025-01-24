#include "FillOutlineState.h"
#include "DragAndDropState.h"
#include "FillShapeState.h"
#include "Toolbar.h"

void FillOutlineState::DragAndDrop(Toolbar* toolbar) const
{
	toolbar->SetState(new DragAndDropState());
}

void FillOutlineState::FillShape(Toolbar* toolbar) const
{
	toolbar->SetState(new FillShapeState());
}

void FillOutlineState::FillOutline(Toolbar* toolbar) const
{
}

