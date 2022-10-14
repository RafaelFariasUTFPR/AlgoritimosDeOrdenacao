#pragma once
#include <string>
#include <iostream>
#include <random>

#include <SFML/Graphics.hpp>
#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MENU_WIDTH 300


class Global
{
public:
	Global() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Algoritimos de ordenação", sf::Style::Titlebar | sf::Style::Close)
	{
		arialFont.loadFromFile("./resources/Roboto-Black.ttf");
		message.setFont(arialFont);
		message.setFillColor(sf::Color::Red);
		message.setCharacterSize(28);
		message.setOutlineColor(sf::Color::Black);
		message.setOutlineThickness(4);

		message.setPosition(sf::Vector2f(10, 10));


	}

	void alert(std::string text);

	int randomInRange(int min, int max);

	double deltaTime;
	std::string windowName;
	sf::Clock deltaClock;
	sf::RenderWindow window;
	sf::Event events;

	sf::Font arialFont;
	sf::Text message;


	std::default_random_engine *generator;



};