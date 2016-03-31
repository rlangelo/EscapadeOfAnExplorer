#include "Dirt.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

Dirt::Dirt()
{
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();

  //Set sprite for dirt
  Sprite *p_temp_sprite;
  p_temp_sprite = rm.getSprite("dirt");

  if (!p_temp_sprite)
    {
      lm.writeLog("Dirt::Dirt(): Warning! Sprite '%s' !found", "dirt");
    }
  else {
    setSprite(p_temp_sprite);
  }

  setType("Dirt");


}

int Dirt::eventHandler(Event *p_e)
{
  return 1;
}
