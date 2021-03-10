#ifndef AI_VIEW_H
#define AI_VIEW_H

#include "game_logic.h"

class AI_View
{
private:
    std::shared_ptr<Game_Logic> game_logic;
    sf::Vector2f ballPos;
    sf::Vector2f ballDim;
    sf::Vector2f ballVel;
    sf::Vector2f sliderPos;
    std::shared_ptr<Slider> AI_slider;
    
public:
    AI_View(std::shared_ptr<Game_Logic> game_logic);

    void AI_Tracking(const float& dt);
    void update(const float& dt);
};
#endif