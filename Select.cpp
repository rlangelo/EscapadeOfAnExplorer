#include "Select.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "Map.h"
#include "GameStart.h"
#include "Select2.h"
#include "Select8.h"
#include "Select14.h"

Select::Select()
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  //Set up the sprite
  Sprite *p_temp_sprite = rm.getSprite("select1");
	if(!p_temp_sprite)
	{
		lm.writeLog("Select::Select(): Warning! Sprite '%s' not found", "select1");
	}
	else
	{
		setSprite(p_temp_sprite);
	}
	lm.writeLog("Inside Select constructor");
	setType("Select");
	setLocation(CENTER_CENTER);
	setSpriteSlowdown(15);
	registerInterest(DF_KEYBOARD_EVENT);
}

int Select::eventHandler(Event *p_e)
{
  GameManager &gm = GameManager::getInstance();
  WorldManager &wm = WorldManager::getInstance();
  if (p_e -> getType() == DF_KEYBOARD_EVENT)
    {
      EventKeyboard *p_key = static_cast <EventKeyboard *> (p_e);
      kbd(p_key);
      return 1;
    }
  return 0;
}

Select::~Select()
{
  //new GameStart;
}

void Select::kbd(EventKeyboard *p_key)
{
  WorldManager &wm = WorldManager::getInstance();
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();
  GameManager &gm = GameManager::getInstance();
  switch(p_key->getKey())
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
      new Select14;
      break;
        case KEY_RIGHT:
	  wm.markForDelete(this);
	  new Select2;
	  break;
    case KEY_DOWN:
      wm.markForDelete(this);
      new Select8;
      break;
	default:
	  break;
    };
  return;
}

void Select::draw()
{
 Object::draw();
}

void Select::start()
{
  int levelNumber = 1;
  new Map(levelNumber);
}
