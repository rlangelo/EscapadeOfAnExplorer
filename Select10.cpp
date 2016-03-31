#include "Select10.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "Map.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Select3.h"
#include "Select11.h"
#include "Select9.h" 

Select10::Select10()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select10");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select10");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Select10");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select10::eventHandler(Event *p_e)
{
  GameManager &gm = GameManager::getInstance();
  WorldManager &wm = WorldManager::getInstance();
  if (p_e -> getType() == DF_KEYBOARD_EVENT)
    {
      EventKeyboard *p_key = (EventKeyboard *) p_e;
      switch (p_key -> getKey())
	{
	case 'm':
	  wm.markForDelete(this);
	  new GameStart;
	  break;
	case 'q':
	  gm.setGameOver();
	  break;
	case 's':
	  wm.markForDelete(this);
	  start();
	  break;
	case KEY_LEFT:
	  wm.markForDelete(this);
	  new Select9;
	  break;
	case KEY_UP:
	  wm.markForDelete(this);
	  new Select3;
	  break;
	case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select11;
	  break;
	default:
	  break;
	}
      return 1;
    }
  return 0;
}

Select10::~Select10()
{
  //new GameStart;
}

void Select10::draw()
{
  Object::draw();
}

void Select10::start()
{
  int levelNumber = 10;
  new Map(levelNumber);
}
