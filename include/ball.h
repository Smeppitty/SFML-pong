#ifndef BALL_H
#define BALL_H

#include "actor.h"
#include "slider.h"

class Ball : public Actor
{   
private:
	sf::Vector2f position;
	sf::Vector2f defaultPos;
	sf::Vector2f dimensions;
	sf::RectangleShape ballShape;
	sf::Vector2f velocity = sf::Vector2f(1.0f, 1.5f);
	float ballSpeed = 200.0f;
	
	//tracks which wall hits (1 = p1, 2 = p2)
	int wallHit = 0;

public:
	Ball(sf::Vector2f position, sf::Vector2f defaultPos, sf::Vector2f dimensions, sf::Color fillColor);

	//shape problems
	sf::Vector2f getVelocity() { return velocity; }
    sf::RectangleShape getShape() { return ballShape; } 

	//handles collision
	void collisionDetection(std::shared_ptr<Slider> slider, sf::Vector2f windowSize);

	//handles tracking which player's wall the ball hits
	int getWallHit(){return wallHit;}
	void resetWallHit() { wallHit = 0;}

	//absolute value function
	float abs(float num);

	void reset(sf::Vector2f windowSize); 
	void update(const float& dt, std::shared_ptr<Slider> slider, sf::Vector2f windowSize);
};
#endif