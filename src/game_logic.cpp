#include "game_logic.h"

Game_Logic::Game_Logic(){}

void Game_Logic::resetGame()
{
    this->p1score = 0;
    this->p2score = 0;

    this->p1 = std::make_shared<Slider>(P1Position, defaultSliderSize, sf::Color::White);
    this->p2 = std::make_shared<Slider>(P2Position, defaultSliderSize, sf::Color::White);

    this->ball = std::make_shared<Ball>(ballPosition, ballPosition, defaultBallSize, sf::Color::White);
}

void Game_Logic::update(const float& dt, const sf::Vector2f windowSize)
{   
    p1->update(dt, windowSize);
    p2->update(dt, windowSize);
    ball->update(dt, p1, windowSize);
    ball->update(dt, p2, windowSize);

    if(ball->getWallHit() == 1)
    {
        this->p1score++;
    }   
    else if(ball->getWallHit() == 2)
    {
        this->p2score++;
    }
    ball->resetWallHit();
}