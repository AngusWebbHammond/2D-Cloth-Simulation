#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"

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

    solver.addVertex({100.0f, 100.0f}, 10.0f, 0, true, {0.0f, 0.0f});
    solver.addVertex({200.0f, 100.0f}, 10.0f, 1, false, {0.0f, 0.0f});
    solver.addVertex({300.0f, 100.0f}, 10.0f, 2, false, {0.0f, 0.0f});
    solver.addVertex({400.0f, 100.0f}, 10.0f, 3, false, {0.0f, 0.0f});
    solver.addVertex({500.0f, 100.0f}, 10.0f, 4, true, {0.0f, 0.0f});
    solver.addVertex({600.0f, 100.0f}, 10.0f, 5, false, {0.0f, 0.0f});
    solver.addVertex({700.0f, 100.0f}, 10.0f, 6, false, {0.0f, 0.0f});
    solver.addVertex({800.0f, 100.0f}, 10.0f, 7, false, {0.0f, 0.0f});
    solver.addVertex({900.0f, 100.0f}, 10.0f, 8, true, {0.0f, 0.0f});

    solver.addVertex({100.0f, 200.0f}, 10.0f, 9, false, {0.0f, 0.0f});
    solver.addVertex({200.0f, 200.0f}, 10.0f, 10, false, {0.0f, 0.0f});
    solver.addVertex({300.0f, 200.0f}, 10.0f, 11, false, {0.0f, 0.0f});
    solver.addVertex({400.0f, 200.0f}, 10.0f, 12, false, {0.0f, 0.0f});
    solver.addVertex({500.0f, 200.0f}, 10.0f, 13, false, {0.0f, 0.0f});
    solver.addVertex({600.0f, 200.0f}, 10.0f, 14, false, {0.0f, 0.0f});
    solver.addVertex({700.0f, 200.0f}, 10.0f, 15, false, {0.0f, 0.0f});
    solver.addVertex({800.0f, 200.0f}, 10.0f, 16, false, {0.0f, 0.0f});
    solver.addVertex({900.0f, 200.0f}, 10.0f, 17, false, {0.0f, 0.0f});

    solver.addLine(0, 1, true, 110.0f);
    solver.addLine(1, 2, true, 110.0f);
    solver.addLine(2, 3, true, 110.0f);
    solver.addLine(3, 4, true, 110.0f);
    solver.addLine(4, 5, true, 110.0f);
    solver.addLine(5, 6, true, 110.0f);
    solver.addLine(6, 7, true, 110.0f);
    solver.addLine(7, 8, true, 110.0f);

    solver.addLine(0, 9, true, 100.0f);
    solver.addLine(1, 10, true, 100.0f);
    solver.addLine(2, 11, true, 100.0f);
    solver.addLine(3, 12, true, 100.0f);
    solver.addLine(4, 13, true, 100.0f);
    solver.addLine(5, 14, true, 100.0f);
    solver.addLine(6, 15, true, 100.0f);
    solver.addLine(7, 16, true, 100.0f);
    solver.addLine(8, 17, true, 100.0f);

    solver.addLine(9, 10, true, 110.0f);
    solver.addLine(10, 11, true, 110.0f);
    solver.addLine(11, 12, true, 110.0f);
    solver.addLine(12, 13, true, 110.0f);
    solver.addLine(13, 14, true, 110.0f);
    solver.addLine(14, 15, true, 110.0f);
    solver.addLine(15, 16, true, 110.0f);
    solver.addLine(16, 17, true, 110.0f);

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