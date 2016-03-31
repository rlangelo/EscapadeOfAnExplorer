#include "GameStart.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "GameManager.h"
#include "EventKeyboard.h"
#include "Map.h"
#include "Select.h"

GameStart::GameStart()
{
	LogManager &lm = LogManager::getInstance();
	ResourceManager &rm = ResourceManager::getInstance();

	//Set up main menu
	Sprite *p_temp_sprite = rm.getSprite("gamestart");
	if(!p_temp_sprite)
	{
		lm.writeLog("GameStart::GameStart(): Warning! Sprite '%s' not found", "gamestart");
	}
	else
	{
		setSprite(p_temp_sprite);
	}
	setType("GameStart");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}


GameStart::~GameStart()
{

}

int GameStart::eventHandler(Event *p_e)
{
	GameManager &gm = GameManager::getInstance();
	WorldManager &wm = WorldManager::getInstance();
	//If it's a keyboard event. s = start, q = quit, h = instructions
	if (p_e->getType() == DF_KEYBOARD_EVENT)
	{
		EventKeyboard *p_key = (EventKeyboard *) p_e;
		switch (p_key->getKey())
		{
			case 's':
			  wm.markForDelete(this);
				start();
				break;
			case 'q':
				gm.setGameOver();
				break;
			default:
				break;
		}
		return 1;
	}
	return 0;
}

//The start function just creates a new map.
void GameStart::start()
{
  
  new Select;
  setActive(false);
}

//Override object's draw method
void GameStart::draw()
{
	Object::draw();
}


	


		
