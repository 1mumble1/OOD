#include "Application.h"
#include "stdafx.h"
#include "ShapeCreator.h"
#include "ShapeMathDecorator.h"
#include "ColorsGenerator.h"
#include "CTriangleMathDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CCircleMathDecorator.h"
#include "ShapeMovableDecorator.h"
#include "SimpleShapeMovableDecorator.h"
#include "CompositeShapeMovableDecorator.h"

Application& Application::GetInstance()
{
	static Application instance;
	return instance;
}

void Application::ReadShapes(const std::string& fileName)
{
	m_handler->ReadShapesFromFile(fileName);
}

void Application::ProcessEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			HandleMousePress(event.mouseButton);
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			HandleMouseRelease(event.mouseButton);
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			HandleMouseMove(event.mouseMove);
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			HandleKeyPress(event.key);
		}
	}
}

void Application::HandleMousePress(const sf::Event::MouseButtonEvent& mouse)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(mouse.x, mouse.y));

	if (mouse.button == sf::Mouse::Left)
	{
		bool isToolButtonPressed = m_toolbar->TryPressToolButton(mousePos);
		m_handler->SetMousePosition(mousePos);
		m_state = m_toolbar->GetState();
		if (!isToolButtonPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				m_state->OnLeftMouseButtonPressedWithShift(m_handler);
			}
			else
			{
				m_state->OnLeftMouseButtonPressed(m_handler, m_toolbar);
			}
		}
	}
}

void Application::HandleMouseRelease(const sf::Event::MouseButtonEvent& mouse)
{
	if (mouse.button == sf::Mouse::Left)
	{
		m_state->OnLeftMouseButtonReleased(m_handler);
	}
}

void Application::HandleMouseMove(const sf::Event::MouseMoveEvent& mouse)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(mouse.x, mouse.y));
	m_handler->SetMousePosition(mousePos);
	m_state->OnMouseMove(m_handler);
}

void Application::HandleKeyPress(const sf::Event::KeyEvent& key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (key.code == sf::Keyboard::G)
		{
			m_state->OnGroup(m_handler);
			return;
		}

		if (key.code == sf::Keyboard::U)
		{
			m_state->OnUngroup(m_handler);
			return;
		}
	}
}

void Application::DrawShapes()
{
	m_window.setVerticalSyncEnabled(true);

	while (m_window.isOpen())
	{
		sf::Event event{};
		ProcessEvents();

		m_window.clear(sf::Color::White);

		for (auto const& shape : m_handler->GetShapes())
		{
			shape->Draw(m_window);
		}

		m_toolbar->Draw();
		m_window.display();
	}
}