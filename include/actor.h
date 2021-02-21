#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include <memory>

class Actor : std::enable_shared_from_this<Actor>
{
private:
    sf::Vector2f position;
public:
    Actor(sf::Vector2f position);
};

#endif