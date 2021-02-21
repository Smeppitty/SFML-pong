#include "ai_view.h"

AI_View::AI_View(std::shared_ptr<Game_Logic> game_logic)
{   
    this->game_logic = game_logic;

}

//get ball and AI slider position
//track the ball in intervals

void AI_View::AI_Tracking(const float& dt) 
{
    this->ballPos = this->game_logic->ballObj()->getShape().getPosition();
    this->sliderPos = this->game_logic->P2()->getShape().getPosition();   
    this->ballDim= this->game_logic->ballObj()->getShape().getSize()/2.0f; 
    this->AI_slider = this->game_logic->P2();

    //this tracks the slider and the ball's position and moves the slider accordingly
    if((this->sliderPos.x - ballPos.x < 400.0f)&& ballPos.y + ballDim.y < sliderPos.y + AI_slider->getShape().getSize().y/2.0f)
    {
        this->AI_slider->addPos(sf::Vector2f(0.0f, -AI_slider->getSpeed()*0.85f));   
    }
    if((this->sliderPos.x - ballPos.x < 400.0f)&&ballPos.y + ballDim.y > sliderPos.y + AI_slider->getShape().getSize().y/2.0f)
    {   
        this->AI_slider->addPos(sf::Vector2f(0.0f, AI_slider->getSpeed()*0.85f));     
    }   
}

void AI_View::update(const float& dt)
{
    if(this->game_logic->getGameMode())
        this->AI_Tracking(dt);
}