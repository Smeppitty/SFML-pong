#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "ball.h"
#include "slider.h"

class Game_Logic
{
private:
    const sf::Vector2f VIEW_SIZE = sf::Vector2f(800.0f,600.0f);

    //Slider Information
    sf::Vector2f P1Position = sf::Vector2f(0.04f * VIEW_SIZE.x, VIEW_SIZE.y/2.0f);
    sf::Vector2f P2Position = sf::Vector2f(0.96f * VIEW_SIZE.x , VIEW_SIZE.y/2.0f);
    sf::Vector2f defaultSliderSize = sf::Vector2f(VIEW_SIZE.x/80.0f, 2.0f * VIEW_SIZE.y/15.0f);

    //Ball information
    sf::Vector2f ballPosition = sf::Vector2f(VIEW_SIZE.x/2.0f, VIEW_SIZE.y/4.0f);
    sf::Vector2f defaultBallSize = sf::Vector2f (VIEW_SIZE.x/60.0f, VIEW_SIZE.x/60.f);

    //Player scores
    int p1score = 0;
    int p2score = 0;

    //gameMode (true = singleplayer, false = multiplayer)
    bool gameMode;  
    bool mainMenuState = true;

    //game states
    bool pauseState = false;
    bool activeState = true;

    std::shared_ptr<Slider> p1 = std::make_shared<Slider>(P1Position, defaultSliderSize, sf::Color::White);
    std::shared_ptr<Slider> p2 = std::make_shared<Slider>(P2Position, defaultSliderSize, sf::Color::White);
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(ballPosition, ballPosition, defaultBallSize, sf::Color::White);


public:
    Game_Logic();
    
    //have game_logic store game objects and their information
    std::shared_ptr<Slider> P1() { return p1; }
    std::shared_ptr<Slider> P2() { return p2; }

    std::shared_ptr<Ball> ballObj() { return ball; }
    
    //window and game state
    void setPauseState(){ if(this->pauseState) this->pauseState=false; else this->pauseState = true;}
    void setPauseState(bool p) { this->pauseState = p; }
    bool getPauseState() { return this->pauseState; }
    void setActiveState(bool a) { this->activeState = a;}
    bool getActiveState() { return this->activeState; }

    //get and set game mode (singleplayer = true, multiplayer = false)
    void setGameMode(bool mode) { this->gameMode = mode; }
    bool getGameMode() { return this->gameMode; }
    
    bool getMainMenuState() { return this->mainMenuState; }

    void resetGame();
    int getP1Score() { return this->p1score; };
    int getP2Score() { return this->p2score; };
    
    void update(const float& dt, const sf::Vector2f windowSize);
};
#endif