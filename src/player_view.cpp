#include "player_view.h"

Player_View::Player_View(std::shared_ptr<Game_Logic> game_logic)
{
    this->game_logic = game_logic;
    this->mainMenuInit();
    this->init();
}

void Player_View::mainMenuInit()
{
    this->font.loadFromFile("../data/fonts/orange kid.ttf");
    this->window->setFramerateLimit(60);
    this->view = sf::View(sf::Vector2f(0.0f, 0.0f), this->windowSize);
    this->view.setCenter(sf::Vector2f(this->window->getSize().x/2.0f, this->window->getSize().y/2.0f));
    this->window->setView(view);

    this->mainMenuState = this->game_logic->getMainMenuState();

    this->pongTitle = sf::Text("Pong", this->font, 80);    
    this->pongTitle.setPosition(sf::Vector2f(this->window->getSize().x / 2.4f, this->window->getSize().y / 4.0f));
    this->pongTitle.setOutlineColor(sf::Color::White);
    this->pongTitle.setFillColor(sf::Color::Black);
    this->pongTitle.setOutlineThickness(5);   

    this->singleplayerOption = sf::Text("Singleplayer", this->font, 60);    
    this->singleplayerOption.setPosition(sf::Vector2f(this->window->getSize().x * 0.15f, this->window->getSize().y / 2.25f));
    this->singleplayerOption.setOutlineColor(sf::Color::White);
    this->singleplayerOption.setFillColor(sf::Color::Black);
    this->singleplayerOption.setOutlineThickness(5);

    this->multiplayerOption = sf::Text("Multiplayer", this->font, 60);    
    this->multiplayerOption.setPosition(sf::Vector2f(this->window->getSize().x * 0.65f, this->window->getSize().y / 2.25f));
    this->multiplayerOption.setOutlineColor(sf::Color::White);
    this->multiplayerOption.setFillColor(sf::Color::Black); 
    this->multiplayerOption.setOutlineThickness(5);   
}

void Player_View::init()
{   
    this->restartText.setFont(this->font);
    this->restartText.setPosition(sf::Vector2f(this->window->getSize().x * 0.25f, this->window->getSize().y * 0.15f));
    this->restartText.setFillColor(sf::Color::White);
    this->restartText.setCharacterSize(80);

    this->p1score.setFont(this->font);
    this->p1score.setPosition(sf::Vector2f(this->window->getSize().x * 0.15f, this->window->getSize().y * 0.05f));
    this->p1score.setFillColor(sf::Color(211,211,211,255));
    this->p1score.setCharacterSize(60);

    this->p2score.setFont(this->font);
    this->p2score.setPosition(sf::Vector2f(this->window->getSize().x * 0.85f, this->window->getSize().y * 0.05f));
    this->p2score.setFillColor(sf::Color(211,211,211,255));
    this->p2score.setCharacterSize(60);
    // this->game_logic->mainMenuON():
}

void Player_View::gameInput(bool gameMode)
{
    bool w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    std::shared_ptr<Slider> player1 = this->game_logic->P1();

    if(w) player1->addPos(sf::Vector2f(0.0f, -player1->getSpeed()));  
    if(s) player1->addPos(sf::Vector2f(0.0f, player1->getSpeed())); 

    if(!gameMode)
    {
        bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

        std::shared_ptr<Slider> player2 = this->game_logic->P2();

        if(up) player2->addPos(sf::Vector2f(0.0f, -player2->getSpeed()));  
        if(down) player2->addPos(sf::Vector2f(0.0f, player2->getSpeed()));   
    } 
}

void Player_View::pollInput()
{
    sf::Event event;
        // process events
    while(this->window->pollEvent(event))
    {
      switch(event.type)
      { //sets gameloop active flag to false 
        case sf::Event::Closed: 
            this->game_logic->setActiveState(false);
            break;

        //handles minimizing/clicking off a window by pausing the draw update
        case sf::Event::GainedFocus:
            this->game_logic->setPauseState(false);
            break;
        case sf::Event::LostFocus:
            this->game_logic->setPauseState(true);
            break;
        
        case sf::Event::Resized:
            this->view.setSize(sf::Vector2f(event.size.width, event.size.height));
            this->window->setView(this->view);
            break;

      //general input
      case sf::Event::KeyPressed:
        switch(event.key.code)
        {
                case sf::Keyboard::Q:
                case sf::Keyboard::Escape:
                    this->game_logic->setActiveState(false);
                    break;                
                
                case sf::Keyboard::P:
                    this->game_logic->setPauseState();
                    break;
                
                case sf::Keyboard::R:
                    this->game_logic->resetGame();
                    break;
                
                case sf::Keyboard::M:
                    this->game_logic->resetGame();
                    this->mainMenuInit();
                    break;
        }
        // handles main menu input
        if(this->mainMenuState)
            {   
                switch(event.key.code)
                {
                case sf::Keyboard::Left:
                    this->singleplayerOption.setFillColor(sf::Color(211,211,211,255));
                    this->multiplayerOption.setFillColor(sf::Color::Black);
                    //singlePlayerOption change color to white
                break;
                
                case sf::Keyboard::Right:
                    this->multiplayerOption.setFillColor(sf::Color(211,211,211,255));
                    this->singleplayerOption.setFillColor(sf::Color::Black);
                    //multiPlayerOption change color to white
                break;
            
                case sf::Keyboard::Enter:
                    if(this->singleplayerOption.getFillColor() == sf::Color(211,211,211,255))
                    {
                        this->mainMenuState = false;
                        this->game_logic->setGameMode(true);
                    }
                    if(this->multiplayerOption.getFillColor() == sf::Color(211,211,211,255))
                    {
                        this->mainMenuState = false;
                        this->game_logic->setGameMode(false);
                    }
                break;
                }
            }               
        }            
    }
}

void Player_View::render()
{   
    this->p1 = this->game_logic->getP1Score();
    this->p2 = this->game_logic->getP2Score();

    this->window->clear();
    
    if(this->mainMenuState)
    {   
        this->window->draw(pongTitle);
        this->window->draw(singleplayerOption);
        this->window->draw(multiplayerOption);
    }

    else if(!this->mainMenuState)
    {
        std::string p1text = std::to_string(this->p1);
        std::string p2text = std::to_string(this->p2);

        this->p1score.setString(p1text);
        this->p2score.setString(p2text);

        this->window->draw(this->p1score);
        this->window->draw(this->p2score);

        this->window->draw(this->game_logic->P1()->getShape());
        this->window->draw(this->game_logic->P2()->getShape());
        this->window->draw(this->game_logic->ballObj()->getShape());
        if(!(this->p1 < 11 && this->p2 < 11))
        {
            if(this->p1==11)
                this->restartText.setString("Player 1 WINS! \n\nRestart? [R] \nMain Menu [M] \nQuit? [Q/Esc]");
            else
                this->restartText.setString("Player 2 WINS! \n\nRestart? [R] \nMain Menu [M] \nQuit? [Q/Esc]");
            this->window->draw(this->restartText);
        }
    }
        this->window->display();
}

void Player_View::update(const float& dt)
{    
    if((this->p1 < 11 && this->p2 < 11) && !this->game_logic->getPauseState() && !this->mainMenuState)
        {
            this->game_logic->update(dt, windowSize);  
            this->gameInput(this->game_logic->getGameMode());
        }
    this->pollInput();
    this->render();
}