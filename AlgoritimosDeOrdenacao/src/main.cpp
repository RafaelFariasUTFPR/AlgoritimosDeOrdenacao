#include <iostream>
#include <stdlib.h>
#include <time.h>




#include "Solver.h"
#include "Global.h"



int main()
{
    std::random_device rd;

    std::default_random_engine generator(rd());

    srand(time(NULL)); // seed

    Global global;
    global.generator = &generator;

    ImGui::SFML::Init(global.window);
    
    Solver solver(global);

    


    while (global.window.isOpen())
    {
        
        while (global.window.pollEvent(global.events))
        {
            ImGui::SFML::ProcessEvent(global.events);
            switch (global.events.type)
            {
            case sf::Event::Closed:
                global.window.close();
            }
        }

        //global.window.setFramerateLimit(15);
        solver.process();
        double fps = 1 / global.deltaTime;

        global.deltaTime = global.deltaClock.getElapsedTime().asSeconds();

        ImGui::SFML::Update(global.window, global.deltaClock.restart());
        ImGui::SetNextWindowSize(ImVec2(MENU_WIDTH, WINDOW_HEIGHT));
        ImGui::SetNextWindowPos(ImVec2(WINDOW_WIDTH - (MENU_WIDTH), 0));
        ImGui::Begin(u8"CONFIGURAÇÃO", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 120));
        ImGui::Text("FPS: %i", (int)fps);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"- Frames por segundo");

        ImGui::SameLine(110);
        ImGui::Text("PPS: %i", solver.sps);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"Passos por segundo");

        ImGui::PopStyleColor();

        ImGui::Spacing();
        if (!isRunning)
        {
            if (ImGui::Button("Gerar vetor"))
            {
                global.alert("Gerando vetor...");

                solver.generateVector();
            }
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip(u8"- Gera um novo vetor com o tamanho desejado");

            ImGui::Spacing();

            ImGui::Checkbox("Visual ", &solver.isVisual);
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip(u8"- Uma representação visual do algoritimo\n\n- Para uma medição da performance real por favor desabilite");
            
            ImGui::Spacing();
            ImGui::PushItemWidth(150);
            ImGui::InputInt("Tamanho do vetor", &solver.vectorSize);
            ImGui::PopItemWidth();
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip(u8"- Define o tamanho do vetor a ser ordenado");

        }
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
        ImGui::InputInt("PPS alvo", &solver.targetSps);
        ImGui::PopItemWidth();
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"- Define a quantidade alvo de PASSOS POR SEGUNDO\n\n- Coloque \"0\" para destravar\n\n- Apenas aplicavel quando \"Visual\" está ativado");
       
        ImGui::Spacing();

        if (!isRunning)
        {
            if (ImGui::TreeNode("ALGORITIMOS"))
            {
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip(u8"- Seleciona o algoritimo que será usado para ordenar o vetor");

                if (ImGui::Button("Bubble Sort"))
                {
                    solver.solveBubbleSort();
                }
                ImGui::TreePop();
            }
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip(u8"- Seleciona o algoritimo que será usado para ordenar o vetor");


        }

        if (isRunning)
        {
            ImGui::Text("Ordenando vetor de tamanho: %i", solver.vectorSize);
            ImGui::TextColored(ImVec4(1, 1, 0.3, 1), "Executando algoritimo...");
        }

       
        ImGui::End();


        global.window.clear(sf::Color(sf::Color::Black));


        solver.showVector();
        ImGui::SFML::Render(global.window);

        global.window.display();

    }

    ImGui::SFML::Shutdown();
}
