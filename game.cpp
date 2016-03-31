#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "GraphicsManager.h"
#include "Hero.h"
#include "Wall.h"
#include "WorldManager.h"
#include "Block.h"
#include "Exit.h"
#include "GameStart.h"

void loadResources(void);
void populateWorld(void);

int main(int argc, char *argv[])
{
  LogManager &lm = LogManager::getInstance();

  GameManager &game_manager = GameManager::getInstance();
  if (game_manager.startUp())
    {
      lm.writeLog("Error starting game manager!");
      game_manager.shutDown();
      return 0;
    }

  lm.setFlush(true);

  splash();
  loadResources();
  populateWorld();

  game_manager.run();

  game_manager.shutDown();

}

void loadResources(void)
{
  ResourceManager &rm = ResourceManager::getInstance();
  rm.loadSprite("sprites/heroright-spr.txt", "explorer-right");
  rm.loadSprite("sprites/wall-spr.txt", "wall");
  rm.loadSprite("sprites/heroleft-spr.txt", "explorer-left");
  rm.loadSprite("sprites/heroup-spr.txt", "explorer-up");
  rm.loadSprite("sprites/herodown-spr.txt", "explorer-down");
  rm.loadSprite("sprites/blockoff-spr.txt", "blockoff");
  rm.loadSprite("sprites/blockon-spr.txt", "blockon");
  rm.loadSprite("sprites/exit-spr.txt", "exit");
  rm.loadSprite("sprites/gamestart-spr.txt", "gamestart");
  rm.loadSprite("sprites/bomb-spr.txt", "bomb");
  rm.loadSprite("sprites/plate-spr.txt", "plate");
  rm.loadSprite("sprites/explosion-spr.txt", "explosion");
  rm.loadSprite("sprites/water-spr.txt", "water");
  rm.loadSprite("sprites/herodie-spr.txt", "death");
  rm.loadSprite("sprites/dirt-spr.txt", "dirt");
  rm.loadSprite("sprites/gate-spr.txt", "gateon");
  rm.loadSprite("sprites/gateoff-spr.txt", "gateoff");
  rm.loadSprite("sprites/select-spr.txt", "select1"); 
  rm.loadSprite("sprites/select2-spr.txt", "select2");
  rm.loadSprite("sprites/select3-spr.txt", "select3");
  rm.loadSprite("sprites/select4-spr.txt", "select4");
  rm.loadSprite("sprites/select5-spr.txt", "select5");
  rm.loadSprite("sprites/select6-spr.txt", "select6");
  rm.loadSprite("sprites/select7-spr.txt", "select7");
  rm.loadSprite("sprites/select8-spr.txt", "select8");
  rm.loadSprite("sprites/select9-spr.txt", "select9");
  rm.loadSprite("sprites/select10-spr.txt", "select10");
  rm.loadSprite("sprites/select11-spr.txt", "select11");
  rm.loadSprite("sprites/select12-spr.txt", "select12");
  rm.loadSprite("sprites/select13-spr.txt", "select13");
  rm.loadSprite("sprites/select14-spr.txt", "select14");
  rm.loadSprite("sprites/tutorial1-spr.txt", "tutorial1");
  rm.loadSprite("sprites/tutorial2-spr.txt", "tutorial2");
  rm.loadSprite("sprites/tutorial3-spr.txt", "tutorial3");
}

void populateWorld(void)
{
	new GameStart();  
}
