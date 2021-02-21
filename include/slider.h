#ifndef SLIDER_H
#define SLIDER_H

#include "actor.h"

class Slider : public Actor
{
private:
	sf::RectangleShape sliderShape;
    sf::Vector2f position;
    sf::Vector2f dimensions;
    int playerNum;
    float sliderSpeed = 10.0f;

public:
	Slider(sf::Vector2f position, sf::Vector2f dimensions, sf::Color fillColor);

    sf::RectangleShape getShape() { return sliderShape; }

    void addPos(sf::Vector2f pos);

    sf::Vector2f getPosition() { return position; }   

    float getSpeed() { return sliderSpeed;}
    
    void collisionDetection(const sf::Vector2f viewSize);

    void draw(std::shared_ptr<sf::RenderWindow> window);
    void update(const float& dt, const sf::Vector2f windowSize);
};
#endif
