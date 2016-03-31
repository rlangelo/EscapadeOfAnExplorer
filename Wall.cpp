#include "Wall.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

Wall::Wall()
{
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();
  
  //set up sprite and object type
  Sprite *p_temp_sprite;
  p_temp_sprite = rm.getSprite("wall");

  if (!p_temp_sprite)
    {
      lm.writeLog("Wall::Wall(): Warning! Sprite '%s' !found", "wall");}
  else {
    setSprite(p_temp_sprite);
  }

  setType("Wall");

  

}


int Wall::eventHandler(Event *p_e)
{
  return 1;
}
