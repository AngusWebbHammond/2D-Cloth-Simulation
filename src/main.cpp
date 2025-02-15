#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"

int main()
{
    constexpr int32_t window_width = 1500;
    constexpr int32_t window_height = 1500;

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "Cloth Simulation",
                            sf::Style::Default, sf::State::Windowed, settings);

    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);
    Solver solver;

    solver.addVertex({300.0f, 300.0f}, 10.0f, 0, true, {0.0f, 0.0f});
    solver.addVertex({500.0f, 500.0f}, 10.0f, 1, false, {0.0f, 0.0f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        solver.update();
        window.clear(sf::Color::Black);

        renderer.update(solver);

        window.display();
    }

    return 0;
}