#include <iostream>
#include <math.h>
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
            calculateJoins();
            updateVerticies();
        }
    }

    std::vector<Vertex> &returnVerticies()
    {
        return verticies;
    }

    std::vector<Line> &returnLines()
    {
        return lines;
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
        verticies[start_vertex_index].connected_to.push_back({end_vertex_index, length});
        verticies[end_vertex_index].connected_to.push_back({start_vertex_index, length});

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

    void calculateJoins()
    {
        float dampening = 0.2f;

        for (Vertex &vertex : verticies)
        {
            for (std::pair<int, float> vertex_index : vertex.connected_to)
            {
                Vertex &connected_vertex = verticies[std::get<0>(vertex_index)];

                sf::Vector2f distance_vect = vertex.position - connected_vertex.position;

                float dist_squared = distance_vect.x * distance_vect.x + distance_vect.y * distance_vect.y;

                float dist = sqrt(dist_squared);

                float line_length = std::get<1>(vertex_index);

                if (dist > line_length)
                {
                    sf::Vector2f normal = distance_vect / dist;

                    if (!connected_vertex.fixed && !vertex.fixed)
                    {
                        float delta = dampening * (dist - line_length);

                        vertex.position -= dampening * normal * delta;
                        connected_vertex.position += dampening * normal * delta;
                    }

                    else if (!connected_vertex.fixed)
                    {
                        float delta = dampening * (dist - line_length);

                        connected_vertex.position += dampening * normal * delta;
                    }

                    else if (!vertex.fixed)
                    {
                        float delta = dampening * (dist - line_length);

                        vertex.position -= dampening * normal * delta;
                    }

                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
};