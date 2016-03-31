#include "Select5.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "Map.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Select6.h"
#include "Select4.h"
#include "Select12.h"

Select5::Select5()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select5");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select5");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Select5");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select5::eventHandler(Event *p_e)
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
	  new Select4;
	  break;
	case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select6;
	  break;
	case KEY_DOWN:
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

Select5::~Select5()
{
  //new GameStart;
}

void Select5::draw()
{
  Object::draw();
}

void Select5::start()
{
  int levelNumber = 5;
  new Map(levelNumber);
}
