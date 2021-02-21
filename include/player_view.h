#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include <iostream>
#include <string>
#include "game_logic.h"

class Player_View
{
private:
    //default window size vector
    sf::Vector2f windowSize = sf::Vector2f(800.0f, 600.0f);
    std::shared_ptr<Game_Logic> game_logic;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);
    sf::View view;
    
    sf::Font font;
    
    //in game text
    sf::Text restartText;
    sf::Text p1score;
    sf::Text p2score;

    //main menu options
    sf::Text singleplayerOption;
    sf::Text multiplayerOption;
    sf::Text pongTitle;
    std::vector<sf::Text> options;

    bool mainMenuState;

    //Player 1 and Player 2 score
    int p1 = 0; 
    int p2 = 0;

public:
    Player_View(std::shared_ptr<Game_Logic> game_logic);

    //sets texts, a framerate limit
    void mainMenuInit();
    void init();
    
    //render the game objects and text
    void render();

    //if gameMode true, only one slider may be controlled and the ai view may control the other, if false, player may control both
    void gameInput(bool gameMode);

    //general input
    void pollInput();

    void update(const float& dt);
};
#endif