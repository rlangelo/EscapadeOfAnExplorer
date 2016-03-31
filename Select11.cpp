#include "Select12.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h" 
#include "Map.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Select4.h"
#include "Select11.h"
#include "Select10.h"

Select11::Select11()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select11");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select11");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Select11");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select11::eventHandler(Event *p_e)
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
	  new Select10;
	  break;
	case KEY_UP:
	  wm.markForDelete(this);
	  new Select4;
	  break;
	case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select12;
	  break;
	default:
	  break;
	}
      return 1;
    }
  return 0;
}

Select11::~Select11()
{
  //new GameStart;
}

void Select11::draw()
{
  Object::draw();
}

void Select11::start()
{
  int levelNumber = 11;
  new Map(levelNumber);
}
