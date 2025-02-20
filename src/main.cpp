#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "cloth.hpp"

int main()
{
    constexpr int32_t window_width = 1000;
    constexpr int32_t window_height = 1000;

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "Cloth Simulation",
                            sf::Style::Default, sf::State::Windowed, settings);

    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);
    Solver solver;

    RectangleCloth cloth({15, 15}, 50.0f, {150.0f, 100.0f});

    cloth.createCloth(solver);

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