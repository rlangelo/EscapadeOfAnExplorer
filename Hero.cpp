#include "Hero.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "Explosion.h"
#include "Block.h"
#include "Death.h"
#include "GameStart.h"
#include <time.h>
#include "Gate.h"

Hero::Hero()
{
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();

  //Set up hero sprite
  Sprite *p_temp_sprite;
  p_temp_sprite = rm.getSprite("explorer-right");

  if (!p_temp_sprite)
    {
      lm.writeLog("Hero::Hero(): Warning! Sprite '%s' !found", "explorer");
    }
  else
    {
      setSprite(p_temp_sprite);
    }

  //Register interest for these events
  registerInterest(DF_KEYBOARD_EVENT);
  registerInterest(DF_STEP_EVENT);

  setType("Hero");
  


}


Hero::~Hero()
{

}

int Hero::eventHandler(Event *p_e)
{
  //If keyboard event call keyboard function
  if (p_e->getType() == DF_KEYBOARD_EVENT) {
    EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
    kbd(p_keyboard_event);
    return 1;
  }

  if (p_e->getType() == DF_STEP_EVENT)
    {
      return 1;
    }
  //If collision call hit function
  	if (p_e->getType() == DF_COLLISION_EVENT)
	{
	  EventCollision *p_collision = static_cast <EventCollision *> (p_e);
	  hit(p_collision);
	  return 1;
	}

  return 0;
}

//kbd function based on function of same name in Professor Claypool's saucer
//shoot tutorial. The difference is that for every direction of key, there
//is a different sprite

void Hero::kbd(EventKeyboard *p_keyboard_event)
{
  WorldManager &wm = WorldManager::getInstance();
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();
  GameManager &gm = GameManager::getInstance();
  Sprite *p_temp_sprite;
  switch(p_keyboard_event->getKey())
    {
    case KEY_UP:
      p_temp_sprite = rm.getSprite("explorer-up");
      if (!p_temp_sprite)
	{
	  lm.writeLog("Hero::Hero(): Warning! Sprite '%s' !found", "explorer");
	}
      else
	{
	  setSprite(p_temp_sprite);
	}
      moveVertical(-1);
      break;
    case KEY_DOWN:
      p_temp_sprite = rm.getSprite("explorer-down");

      if (!p_temp_sprite)
	{
	  lm.writeLog("Hero::Hero(): Warning! Sprite '%s' !found", "explorer");
	}
      else
	{
	  setSprite(p_temp_sprite);
	}
      moveVertical(1);
      break;
    case KEY_LEFT:
      p_temp_sprite = rm.getSprite("explorer-left");

      if (!p_temp_sprite)
	{
	  lm.writeLog("Hero::Hero(): Warning! Sprite '%s' !found", "explorer");
	}
      else
	{
	  setSprite(p_temp_sprite);
	}
      moveHorizontal(-1);
      break;
    case KEY_RIGHT:
      p_temp_sprite = rm.getSprite("explorer-right");

      if (!p_temp_sprite)
	{
	  lm.writeLog("Hero::Hero(): Warning! Sprite '%s' !found", "explorer");
	}
      else
	{
	  setSprite(p_temp_sprite);
	}
      moveHorizontal(1);
      break;
    case 'q':
      //gm.setGameOver();
      Explosion *p_ex = new Explosion;
      p_ex -> setPosition(this -> getPosition());
      break;
    };
  return;
}

//Move function to move the hero vertically
void Hero::moveVertical(int dy)
{
  WorldManager &wm = WorldManager::getInstance();
 
  Position new_pos(getPosition().getX(), getPosition().getY() + dy);
  if ((new_pos.getY() >= 0) && (new_pos.getY() < wm.getBoundary().getVertical()))
    {
      wm.moveObject(this, new_pos);
    }
}

//Move function to move the hero horizontally
void Hero::moveHorizontal(int dx)
{
  WorldManager &wm = WorldManager::getInstance();

  Position new_pos(getPosition().getX() + dx, getPosition().getY());
  if ((new_pos.getX() > 0) && (new_pos.getX() < wm.getBoundary().getHorizontal()))
    {
      wm.moveObject(this, new_pos);

    }
}



//Collision function for hero
void Hero::hit(EventCollision *p_c)
{
  WorldManager &wm = WorldManager::getInstance();

  //If hero collides with block move both hero and block
	if ((p_c -> getObject1() -> getType() == "Block") &&
		(p_c -> getObject2() -> getType() == "Hero"))
	{
	  if (p_c -> getObject1() -> getPosition().getX() > p_c -> getObject2()-> getPosition().getX())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2());
		  p_h -> moveHorizontal(1);

		}
	  else if (p_c -> getObject1() -> getPosition().getX() < 
		   p_c -> getObject2() -> getPosition().getX())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2());
		  p_h -> moveHorizontal(-1);
		  
		}
		else if (p_c -> getObject1() -> getPosition().getY() > 
				p_c -> getObject2() -> getPosition().getY())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2()); 
		  p_h -> moveVertical(1);
		}
		else
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2()); 
		  p_h -> moveVertical(-1);
		}
	}
     else if ((p_c -> getObject1() -> getType() == "Hero") &&
		(p_c -> getObject2() -> getType() == "Block"))
	{
	  if (p_c -> getObject1() -> getPosition().getX() > p_c -> getObject2()->getPosition().getX())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2()); 
		  p_h -> moveHorizontal(-1);
		}
	  else if (p_c -> getObject1() -> getPosition().getX() < 
		   p_c -> getObject2()->getPosition().getX())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2());
		  p_h -> moveHorizontal(1);
		}
		else if (p_c -> getObject1() -> getPosition().getY() > 
				p_c -> getObject2() -> getPosition().getY())
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2());
		  p_h -> moveVertical(-1);
		}
		else
		{
		  Hero *p_h = static_cast <Hero *> (p_c -> getObject2());
		  p_h -> moveVertical(1);
		}
	}

	//If hero gets to the exit, back to the main menu.
      else if ((p_c -> getObject1() -> getType() == "Exit") ||
		  (p_c -> getObject2() -> getType() == "Exit"))
	{
	  //GameManager &gm = GameManager::getInstance();
	  wm.markForDelete(p_c -> getObject1());
	  wm.markForDelete(p_c -> getObject2());
	}

	//If hero touches bomb, BOOM. Back to main menu
      else if ((p_c -> getObject1() -> getType() == "Bomb") ||
	       (p_c -> getObject2() -> getType() == "Bomb"))
	{
	  
	  wm.markForDelete(p_c -> getObject1());
	  wm.markForDelete(p_c -> getObject2());
	  Explosion *p_ex = new Explosion;
	  p_ex -> setPosition(this -> getPosition());

	}

	//If hero steps on dirt, the dirt is cleared     
      else if (p_c -> getObject1() -> getType() == "Dirt")
	{
	  wm.markForDelete(p_c->getObject1());
	}
      else if (p_c -> getObject2() -> getType() == "Dirt")
	{
	  wm.markForDelete(p_c -> getObject2());
	}

	//If hero falls in the water, he drowns. Back to main menu
      else if ((p_c -> getObject1() -> getType() == "Water") ||
	       (p_c -> getObject2() -> getType() == "Water"))
	{
	  wm.markForDelete(p_c -> getObject1());
	  wm.markForDelete(p_c -> getObject2());
	  Death *p_d = new Death;
	  if (p_c -> getObject1() -> getType() == "Water")
	    {
	      p_d -> setPosition(p_c -> getObject1() -> getPosition());
	    }
	  else
	    {
	      p_d -> setPosition(p_c -> getObject2() -> getPosition());
	    }

	}

}
	


