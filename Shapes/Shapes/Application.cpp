#include "Application.h"

Application::Application(const std::string& inputFileName, const std::string outputFileName)
	: m_inputFileName(inputFileName)
	, m_outputFileName(outputFileName)
{
	m_shapeController = new ShapeController(inputFileName, outputFileName);
}

Application* Application::m_instance = nullptr;

Application* Application::GetInstance(const std::string& inputFileName, const std::string outputFileName)
{
	if (m_instance == nullptr)
	{
		m_instance = new Application(inputFileName, outputFileName);
	}

	return m_instance;
}

void Application::Run()
{
	m_shapeController->ReadShapes();
	m_shapeController->PrintShapesInfo();
	m_shapeController->DrawShapes();
}