#pragma once
#include "stdafx.h"

class ColorsGenerator
{
public:
	ColorsGenerator() = default;

	sf::Color GetRandomColor()
	{
		GenerateRandomColor();
		return sf::Color(m_r, m_g, m_b);
	}

private:
	void GenerateRandomColor()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(MIN_RGB_COLOR_VALUE, MAX_RGB_COLOR_VALUE);

		m_r = dist(gen);
		m_g = dist(gen);
		m_b = dist(gen);
	}

	int m_r = 0, m_g = 0, m_b = 0;
};