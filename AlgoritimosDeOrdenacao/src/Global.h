#pragma once
#include <string>

#include <SFML/Graphics.hpp>
#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MENU_WIDTH 400


class Global
{
public:
	Global() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Algoritioms de ordenação", sf::Style::Titlebar | sf::Style::Close)
	{

	}

	double deltaTime;
	std::string windowName;
	sf::Clock deltaClock;
	sf::RenderWindow window;
	sf::Event events;






};