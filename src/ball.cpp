#include "ball.h"

Ball::Ball(sf::Vector2f position, sf::Vector2f defaultpos, sf::Vector2f dimensions, sf::Color fillColor) : Actor(position)
{
    this->position = position;
    this->dimensions = dimensions;
    this->defaultPos = defaultPos;
    this->ballShape.setPosition(position);
    this->ballShape.setSize(dimensions);
    this->ballShape.setOrigin(dimensions.x/2.0f, dimensions.y/2.0f);
    this->ballShape.setFillColor(fillColor);
}

//collision detection with the ball and a slider and return a 0 or 1 to show which player scored
void Ball::collisionDetection(std::shared_ptr<Slider> slider, sf::Vector2f windowSize)
{
    //ball to top and bottom of screen 
    if (ballShape.getPosition().y - this->dimensions.y < 0.0f)
        velocity.y = 1.5f;
    if (ballShape.getPosition().y + this->dimensions.y > windowSize.y)
        velocity.y = -1.5f;

    //ball to player 1 and player 2 side collision
    if(ballShape.getPosition().x + this->dimensions.x > windowSize.x)
    {
        this->reset(windowSize);
        //player 2 wall's hit
        wallHit = 1;
    }
    if(ballShape.getPosition().x - this->dimensions.x < 0.0f)
    {
        this->reset(windowSize);
        //player 1 wall's hit
        wallHit = 2;
    }   

    // ball to slider collision
    float distanceX = ballShape.getPosition().x - slider->getShape().getPosition().x;
    float distanceY = ballShape.getPosition().y - slider->getShape().getPosition().y;

    float sumX = ballShape.getSize().x/2.0f + slider->getShape().getSize().x/2.0f;
    float sumY = ballShape.getSize().y/2.0f + slider->getShape().getSize().y/2.0f;

    if(abs(distanceX) < sumX && abs(distanceY) < sumY)
    {
        if(velocity.x<0.0f)
            ballShape.move(1.25f * slider->getShape().getSize().x + 2.0f, 0.0f);
        if(velocity.x>0.0f)
            ballShape.move(-1.25f * slider->getShape().getSize().x + 2.0f, 0.0f);
        velocity.x *= -1.0f;

    }
}

float Ball::abs(float num)
{
    if(num < 0.0f)
        return num*-1.0f;
    return num;
}

//reset the ball after it hits a player's wall
void Ball::reset(sf::Vector2f windowSize)
{
    this->position = sf::Vector2f(windowSize.x/2.0f, windowSize.y/4.0f);
    this->velocity.x *= -1.0f;
    ballShape.setPosition(this->position);
}

void Ball::update(const float& dt, std::shared_ptr<Slider> slider, sf::Vector2f windowSize)
{
    this->ballShape.move(dt * velocity * ballSpeed);
    this->collisionDetection(slider, windowSize);
}
