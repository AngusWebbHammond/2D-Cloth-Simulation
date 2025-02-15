#include <SFML/Graphics.hpp>

struct Vertex
{
    sf::Vector2f position;
    sf::Vector2f last_position;
    sf::Vector2f acceleration = {0.0f, 0.0f};
    float radius;
    int vertex_index;
    bool fixed;

    Vertex() = default;
    Vertex(sf::Vector2f position_, float radius_, int vertex_index_, bool fixed_)
        : last_position{position_},
          position{position_},
          radius{radius_},
          vertex_index{vertex_index_},
          fixed{fixed_}
    {
    }

    void update(float dt)
    {
        if (!fixed) // If the vertex is fixed, we do not run the Verlet Integration
        {
            sf::Vector2f displacement = position - last_position;
            last_position = position;
            position = position + displacement + acceleration * dt * dt;
            acceleration = {};
        }
    }

    sf::Vector2f getVelocity()
    {
        return position - last_position;
    }

    void addVelcity(sf::Vector2f v, float dt)
    {
        last_position -= v * dt;
    }

    void setVelocity(sf::Vector2f v, float dt)
    {
        last_position = position - v * dt;
    }

    void accelerate(sf::Vector2f a)
    {
        acceleration += a;
    }

    void draw(sf::RenderTarget &target, sf::CircleShape &circle, sf::Color colour)
    {
        circle.setRadius(radius);
        circle.setOrigin({radius, radius});
        circle.setFillColor(colour);
        circle.setPosition(position);
        target.draw(circle);
    }
};
