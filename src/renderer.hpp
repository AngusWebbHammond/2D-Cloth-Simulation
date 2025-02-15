#include <SFML/Graphics.hpp>
#include "solver.hpp"

class Renderer
{
public:
    Renderer(sf::RenderTarget &_target) : target{_target} {}

    void update(Solver &solver)
    {
        sf::CircleShape circle(10.0f);
        circle.setPointCount(32);

        std::vector<Vertex> &verticies = solver.returnVerticies();

        for (Vertex &vertex : verticies)
        {
            vertex.draw(target, circle, sf::Color::White);
        }
    }

private:
    sf::RenderTarget &target;
};