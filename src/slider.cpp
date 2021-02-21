#include "slider.h"

Slider::Slider(sf::Vector2f position, sf::Vector2f dimensions, sf::Color fillColor) : Actor(position)
{   
    this->position = position;
    this->dimensions = dimensions;
    this->sliderShape.setPosition(position);
    this->sliderShape.setSize(dimensions);
    this->sliderShape.setOrigin(dimensions.x/2.0f,dimensions.y/2.0f);
    this->sliderShape.setFillColor(fillColor);
}

void Slider::addPos(sf::Vector2f pos)
{    
        if(this->sliderShape.getPosition().y + pos.y < 600.0f && this->sliderShape.getPosition().y + pos.y*2> 0.0f)
            this->sliderShape.setPosition(this->sliderShape.getPosition() + pos);
}

void Slider::collisionDetection(const sf::Vector2f windowSize)
{
    if (this->sliderShape.getPosition().y + this->dimensions.y / 2.0f > windowSize.y)
    {
        this->sliderShape.move(0.0f, -this->sliderSpeed);
    }
    if ( this->sliderShape.getPosition().y - this->dimensions.y / 2.0f < 0.0f)
    {   
        this->sliderShape.move(0.0f, this->sliderSpeed);    
    }
}

void Slider::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->sliderShape);
}

void Slider::update(const float& dt, const sf::Vector2f windowSize)
{   
    this->collisionDetection(windowSize);
}