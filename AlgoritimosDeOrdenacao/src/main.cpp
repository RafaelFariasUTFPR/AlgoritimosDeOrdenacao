#include <iostream>
#include <stdlib.h>
#include <time.h>


#include <SFML/Graphics.hpp>
#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

#include "Solver.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MENU_WIDTH 400


int main()
{
    srand(time(NULL)); // seed


    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Algoritioms de ordenação", sf::Style::Titlebar | sf::Style::Close);

    ImGui::SFML::Init(window);
    
    Solver solver;

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
        ImGui::SetNextWindowSize(ImVec2(MENU_WIDTH, WINDOW_HEIGHT));
        ImGui::SetNextWindowPos(ImVec2(WINDOW_WIDTH - (MENU_WIDTH), 0));
        ImGui::Begin(u8"CONFIGURAÇÃO", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        
        if (ImGui::Button("Gerar vetor"))
        {
            solver.generateVector();
        }

        ImGui::Checkbox("Visual ", &solver.isVisual);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"- Uma representação visual do algoritimo\n\n- Para uma medição da performance real por favor desabilite");
        /*
        if (ImGui::TreeNode("Representacao visual"))
        {
            ImGui::Spacing();
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 255, 120));
            ImGui::TextWrapped("Uma representacao visual do algoritimo, para uma medicao da performance real por favor desabilite\n\n");
            ImGui::PopStyleColor();
            ImGui::Checkbox("Visual ", &isVisual);
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip(u8"Uma representação visual do algoritimo\nPara uma medição da performance real por favor desabilite");
            ImGui::TreePop();
        }
        */
        ImGui::Spacing();
        ImGui::PushItemWidth(150);
        ImGui::InputInt("Tamanho do vetor", &solver.vectorSize);
        ImGui::PopItemWidth();
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"- Define o tamanho do vetor a ser ordenado");

        ImGui::Spacing();
        ImGui::PushItemWidth(150);
        ImGui::InputInt("PPS", &solver.sps);
        ImGui::PopItemWidth();
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"- Define a quantidade de PASSOS POR SEGUNDO\n\n- Coloque \" 0 \" para definir como infinito\n\n- Apenas aplicavel quando \"Visual\" está ativado");

       
        ImGui::End();


        window.clear(sf::Color(sf::Color::Black));

        ImGui::SFML::Render(window);

        window.display();

    }

    ImGui::SFML::Shutdown();
}
