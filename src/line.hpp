#include <cmath>

#define M_PI 3.14159265358979323846

struct Line
{
  int start_vertex_index;
  int end_vertex_index;
  bool compressible;
  float length;

  Line() = default;
  Line(int start_vertex_index_, int end_vertex_index_, bool compressible_, float length_)
      : start_vertex_index{start_vertex_index_},
        end_vertex_index{end_vertex_index_},
        compressible{compressible_},
        length{length_} {}

  void draw(sf::RenderTarget &target, sf::RectangleShape line, Vertex vertex1, Vertex vertex2)
  {
    sf::Vector2f vertex1_pos = vertex1.position;
    sf::Vector2f vertex2_pos = vertex2.position;

    sf::Vector2f difference_vector = vertex1_pos - vertex2_pos;

    float difference = sqrt(difference_vector.x * difference_vector.x + difference_vector.y * difference_vector.y);

    float angle;

    if (vertex1_pos.x == vertex2_pos.x)
    {
      angle = M_PI / 2;
    }

    else if (vertex2_pos.x > vertex1_pos.x)
    {
      angle = atan((vertex2_pos.y - vertex1_pos.y) / (vertex2_pos.x - vertex1_pos.x));
    }

    else if (vertex2_pos.x < vertex1_pos.x)
    {
      angle = atan((vertex2_pos.x - vertex1_pos.x) / (vertex1_pos.y - vertex2_pos.y)) + M_PI / 2;
    }

    else
    {
      angle = -atan((vertex2_pos.y - vertex1_pos.y) / (vertex2_pos.x - vertex1_pos.x));
    }

    line.setSize({difference, 5.0f});
    line.setFillColor(sf::Color::White);

    line.setPosition(vertex1_pos);
    line.setRotation(sf::radians(angle));
    target.draw(line);
  }
};