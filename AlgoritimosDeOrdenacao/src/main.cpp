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

    solver.generateVector();

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

        global.window.setFramerateLimit(144);
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

        //ImGui::Text(std::to_string(ImGui::GetTime()));
        ImGui::SameLine(110);
        if(solver.targetSps == 0)
            ImGui::Text("PPS: Destravado");
        else
            ImGui::Text("PPS: %li", solver.sps);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip(u8"Passos por segundo");

        ImGui::PopStyleColor();

        ImGui::Spacing();
        
        if (!isRandomizing)
        {
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
                    if (ImGui::Button("Quick Sort"))
                    {
                        solver.solveQuickSort();
                    }
                    if (ImGui::Button("Counting Sort"))
                    {
                        solver.solveCountingSort();
                    }
                    ImGui::TreePop();
                }
            }
        }
        
        if(isRandomizing)
        {
            ImGui::Text("Gerando vetor de tamanho: %i", solver.vectorSize);
            ImGui::TextColored(ImVec4(1, 1, 0.3, 1), "GERANDO VETOR...");
        }
        ImGui::Spacing();
        ImGui::Spacing();

        if (isRunning)
        {
            ImGui::Text("Ordenando vetor de tamanho: %i", solver.vectorSize);
            ImGui::TextColored(ImVec4(1, 1, 0.3, 1), "Executando algoritimo...");
        }
        ImGui::Spacing();
        ImGui::Spacing();

        ImGui::Text(u8"RESULTADO ANTERIOR");

        ImGui::BeginListBox("", ImVec2(MENU_WIDTH-15, 150));

        ImGui::Text(u8"Tempo de execução:");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0.2, 0.2, 1), "%f ms", lastExecutionTime);

        if (ImGui::Button("Copiar tempo"))
        {
            ImGuiIO& io = ImGui::GetIO(); 
            io.SetClipboardTextFn(nullptr, std::to_string(lastExecutionTime).c_str());
        }

        ImGui::Text(u8"Numero de passos:");
        ImGui::SameLine();
        if(lastNumberOfSteps < 1000000)
            ImGui::TextColored(ImVec4(1, 0.2, 0.2, 1), "%lu", lastNumberOfSteps);
        else
        {
            ImGui::TextColored(ImVec4(1, 0.2, 0.2, 1), "%lu E6", lastNumberOfSteps / 1000000);
        }

        if (ImGui::Button("Copiar passos"))
        {
            ImGuiIO& io = ImGui::GetIO();
            io.SetClipboardTextFn(nullptr, std::to_string(lastNumberOfSteps).c_str());
        }

        ImGui::EndListBox();

        ImGui::End();

        global.window.clear(sf::Color(sf::Color::Black));

        solver.showVector();
        ImGui::SFML::Render(global.window);

        global.window.display();

    }

    ImGui::SFML::Shutdown();
}
