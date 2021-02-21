#include <SFML/Graphics.hpp>

#include "game_logic.h"
#include "player_view.h"
#include "ai_view.h"

int main(int argc, char** argv)
{
  std::shared_ptr<Game_Logic> game_logic = std::make_shared<Game_Logic>();
  std::shared_ptr<Player_View> player_view = std::make_shared<Player_View>(game_logic);
  std::shared_ptr<AI_View> ai_view = std::make_shared<AI_View>(game_logic);

  // start main loop
  sf::Clock dtClock;  
  float dt = 0.0f;
  while(game_logic->getActiveState())
  {
      dt = dtClock.restart().asSeconds();
      player_view->update(dt);
      ai_view->update(dt);      
  }

  // Done.
  return 0;
}
