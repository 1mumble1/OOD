#include "History.h"

void History::UpdateHistory(std::shared_ptr<ShapeMemento> state)
{
	m_history.push(state);
}

std::shared_ptr<ShapeMemento> History::Undo()
{
	if (m_history.empty())
	{
		printf("empty stack");
		return nullptr;
	}

	std::shared_ptr<ShapeMemento> state = m_history.top();
	m_history.pop();

	if (m_history.empty())
	{
		printf("do not have previous state");
		m_history.push(state);
		return nullptr;
	}

	return m_history.top();
}
