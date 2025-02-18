#include <SFML/Graphics.hpp>
// #include "solver.hpp"

struct RectangleCloth
{
  sf::Vector2i num_verticies;
  float line_length;
  sf::Vector2f start_postion;

  RectangleCloth() = default;
  RectangleCloth(sf::Vector2i num_verticies_, float line_length_, sf::Vector2f start_postion_)
      : num_verticies{num_verticies_},
        line_length{line_length_},
        start_postion{start_postion_} {}

  void createCloth(Solver &solver)
  {
    bool fixed = false;
    for (int i = 0; i < num_verticies.x; i++)
    {
      for (int j = 0; j < num_verticies.y; j++)
      {
        if ((i == 0 && j == 0) || (j == 0 && i == num_verticies.x - 1))
        {
          fixed = true;
        }
        solver.addVertex(start_postion + sf::Vector2f{line_length * i, line_length * j}, 10.0f, i * num_verticies.y + j, fixed, {0.0f, 0.0f});
        fixed = false;
      }
    }
  }
};