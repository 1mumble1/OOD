#pragma once
#include "stdafx.h"
#include "ShapeController.h"

class Application
{
public:
	static Application* GetInstance(const std::string& inputFileName, const std::string outputFileName);

	void Run();

private:
	Application(const std::string& inputFileName, const std::string outputFileName);

	std::string m_inputFileName, m_outputFileName;

	static Application* m_instance;
	ShapeController* m_shapeController;
};

