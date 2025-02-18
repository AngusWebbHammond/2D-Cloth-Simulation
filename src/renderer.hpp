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

        sf::RectangleShape rectangle;
        rectangle.setOrigin({2.5, 2.5});

        std::vector<Vertex> &verticies = solver.returnVerticies();
        std::vector<Line> &lines = solver.returnLines();

        for (Vertex &vertex : verticies)
        {
            vertex.draw(target, circle, sf::Color::White);
        }

        for (Line &line : lines)
        {
            line.draw(target, rectangle, verticies[line.start_vertex_index], verticies[line.end_vertex_index]);
        }
    }

private:
    sf::RenderTarget &target;
};