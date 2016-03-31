#include "Water.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

Water::Water()
{
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();

  //set up sprite, object type and solidness of object
  Sprite *p_temp_sprite;
  p_temp_sprite = rm.getSprite("water");

  if (!p_temp_sprite)
    {
      lm.writeLog("Water::Water(): Warning! Sprite '%s' !found", "water");}
  else {
    setSprite(p_temp_sprite);
  }

  setType("Water");
  setSolidness(SOFT);


}

int Water::eventHandler(Event *p_e)
{
  return 1;
}
