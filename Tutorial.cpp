#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Tutorial.h"
#include "Exit.h"
#include "Position.h"
#include "Block.h"
#include "Water.h"
#include "Bomb.h"
#include "Plate.h"
#include "Gate.h"
#include "Dirt.h"

Tutorial::Tutorial(int levelNumber)
{
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();

  if (levelNumber == 1)
    {
      Sprite *p_temp_sprite = rm.getSprite("tutorial1");
      if(!p_temp_sprite)
	{
	  lm.writeLog("Tutorial::Tutorial(): Warning! Sprite '%s' not found", "tutorial1");
	 }
      else
	{
	  setSprite(p_temp_sprite);
	}
      Object *p_h = new Exit;
      Position pos;
      pos.setXY(20 ,2);
      p_h -> setPosition(pos);
      Object *p_b = new Block;
      pos.setXY(15, 3);
      p_b -> setPosition(pos);
    }

  else if (levelNumber == 2)
    {
      Sprite *p_temp_sprite = rm.getSprite("tutorial2");
      if(!p_temp_sprite)
	{
	  lm.writeLog("Tutorial::Tutorial(): Warning! Sprite '%s' not found", "tutorial2");
	 }
      else
	{
	  setSprite(p_temp_sprite);
	}

      Object *p_h = new Water;
      Position pos;
      pos.setXY(26 ,1);
      p_h -> setPosition(pos);
      Object *p_bl = new Block;
      pos.setXY(35, 3);
      p_bl -> setPosition(pos);
      p_bl -> setAltitude(0);
      Object *p_b = new Bomb;
      pos.setXY(23, 2);
      p_b -> setPosition(pos);
      Object *p_p = new Plate;
      pos.setXY(35, 3);
      p_p -> setAltitude(2);
      p_p -> setPosition(pos);
      Object *p_g = new Gate;
      pos.setXY(26 ,4);
      p_g -> setPosition(pos);
    }

  else if (levelNumber == 4)
    {
      Sprite *p_temp_sprite = rm.getSprite("tutorial3");
      if(!p_temp_sprite)
	{
	  lm.writeLog("Tutorial::Tutorial(): Warning! Sprite '%s' not found", "tutorial3");
	 }
      else
	{
	  setSprite(p_temp_sprite);
	}

      Object *p_h = new Dirt;
      Position pos;
      pos.setXY(24 ,2);
      p_h -> setPosition(pos);
    }

     setType("Tutorial");
     setLocation(TOP_LEFT);
     setAltitude(1);
}

Tutorial::~Tutorial()
{

}

int Tutorial::eventHandler(Event *p_e)
{
  return 1;
}

void Tutorial::draw()
{
  Object::draw();
}
