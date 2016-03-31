#include "Select13.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "Map.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Select5.h" 
#include "Select11.h"
#include "Select12.h"

Select12::Select12()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select12");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select12");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Select12");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select12::eventHandler(Event *p_e)
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
	  new Select11;
	  break;
	case KEY_UP:
	  wm.markForDelete(this);
	  new Select5;
	  break;
	case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select13;
	  break;
	default:
	  break;
	}
      return 1;
    }
  return 0;
}

Select12::~Select12()
{
  //new GameStart;
}

void Select12::draw()
{
  Object::draw();
}

void Select12::start()
{
  int levelNumber = 12;
  new Map(levelNumber);
}
