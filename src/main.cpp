#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

int main()
{
    auto window = sf::RenderWindow{ { 1280u, 720u }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    ImGui::SFML::Init(window);

    sf::Clock clock;
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, clock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
