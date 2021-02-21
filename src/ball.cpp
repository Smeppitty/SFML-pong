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
    if (this->ballShape.getPosition().y - this->dimensions.y < 0.0f)
        this->velocity.y = 1.5f;
    if (this->ballShape.getPosition().y + this->dimensions.y > windowSize.y)
        this->velocity.y = -1.5f;

    //ball to player 1 and player 2 side collision
    if(this->ballShape.getPosition().x + this->dimensions.x > windowSize.x)
    {
        this->reset(windowSize);
        //player 2 wall's hit
        this->wallHit = 1;
    }
    if(this->ballShape.getPosition().x - this->dimensions.x < 0.0f)
    {
        this->reset(windowSize);
        //player 1 wall's hit
        this->wallHit = 2;
    }   

    // ball to slider collision
    float distanceX = this->ballShape.getPosition().x - slider->getShape().getPosition().x;
    float distanceY = this->ballShape.getPosition().y - slider->getShape().getPosition().y;

    float sumX = this->ballShape.getSize().x/2.0f + slider->getShape().getSize().x/2.0f;
    float sumY = this->ballShape.getSize().y/2.0f + slider->getShape().getSize().y/2.0f;

    if(abs(distanceX) < sumX && abs(distanceY) < sumY)
    {
        if(this->velocity.x<0.0f)
            this->ballShape.move(1.25f * slider->getShape().getSize().x + 2.0f, 0.0f);
        if(this->velocity.x>0.0f)
            this->ballShape.move(-1.25f * slider->getShape().getSize().x + 2.0f, 0.0f);
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
    this->ballShape.setPosition(this->position);
}

void Ball::update(const float& dt, std::shared_ptr<Slider> slider, sf::Vector2f windowSize)
{
    this->ballShape.move(dt * velocity * ballSpeed);
    this->collisionDetection(slider, windowSize);
}
