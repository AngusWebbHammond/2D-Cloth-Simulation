#include <iostream>
#include "vertex.hpp"
#include "line.hpp"

class Solver
{
public:
    void update()
    {
        for (int i = 0; i < subStep; i++)
        {
            applyGravity();
            updateVerticies();
        }
    }

    std::vector<Vertex> &returnVerticies()
    {
        return verticies;
    }

    void addVertex(sf::Vector2f initial_position, float radius, int vertex_index, bool fixed, sf::Vector2f acceleration)
    {
        Vertex vertex(initial_position, radius, vertex_index, fixed);

        if (!fixed)
        {
            vertex.accelerate(acceleration);
        }

        verticies.push_back(vertex);
    }

    void addLine(int start_vertex_index, int end_vertex_index, bool compressible, float length)
    {
        Line line(start_vertex_index, end_vertex_index, compressible, length);

        lines.push_back(line);
    }

private:
    std::vector<Vertex> verticies;
    std::vector<Line> lines;

    int subStep = 8;
    float dt = 1.0f / 60;

    sf::Vector2f gravity = {0.0f, 200.0f / subStep};

    void applyGravity()
    {
        for (Vertex &vertex : verticies)
        {
            if (!vertex.fixed)
            {
                vertex.accelerate(gravity);
            }
        }
    }

    void updateVerticies()
    {
        for (Vertex &vertex : verticies)
        {
            vertex.update(dt);
        }
    }
};