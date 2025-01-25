#include "ShapeMemento.h"

std::vector<IShapePtr> ShapeMemento::GetState()
{
    return m_state;
}
