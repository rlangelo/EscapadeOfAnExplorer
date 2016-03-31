#include "Select4.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "Map.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Select5.h"
#include "Select3.h"
#include "Select11.h"

Select4::Select4()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select4");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select4");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Select4");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select4::eventHandler(Event *p_e)
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
	  new Select3;
	  break;
	case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select5;
	  break;
	case KEY_DOWN:
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

Select4::~Select4()
{
  //new GameStart;
}

void Select4::draw()
{
  Object::draw();
}

void Select4::start()
{
  int levelNumber = 4;
  new Map(levelNumber);
}
