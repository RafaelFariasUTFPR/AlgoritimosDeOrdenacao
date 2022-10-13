#include <iostream>

#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Algoritioms de ordenação");

    ImGui::SFML::Init(window);


    sf::Event e;

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            ImGui::SFML::ProcessEvent(e);
            switch (e.type)
            {
            case sf::Event::Closed:
                window.close();
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Janela");
        ImGui::Text("Sou uma janela do ImGui");
        ImGui::End();


        window.clear(sf::Color(sf::Color::Black));

        ImGui::SFML::Render(window);

        window.display();

    }

    ImGui::SFML::Shutdown();
}
