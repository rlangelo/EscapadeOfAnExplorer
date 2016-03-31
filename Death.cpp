/***********************************************************************************************************************************************************************************************************************************************Based on Explosion class from Professor Claypool's Saucer Shoot Tutorial
 **************************************************************************************************/

#include "Death.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "EventStep.h"
#include "GameStart.h"
#include "Select.h"

Death::Death() {
  LogManager &log_manager = LogManager::getInstance();
  ResourceManager &resource_manager = ResourceManager::getInstance();

  //Setup explosion sprite
  Sprite *p_temp_sprite = resource_manager.getSprite("death");
  if (!p_temp_sprite) {
    log_manager.writeLog("Death::Death(): Warning! Sprite '%s' !found", "death");
  }
  setSprite(p_temp_sprite);
  setType("Death");
  registerInterest(DF_STEP_EVENT);


  //set live time as long as sprite length
  time_to_live = getSprite()->getFrameCount() * 5;

  //set solidness of explosion
  setSolidness(SPECTRAL);
  setSpriteSlowdown(2);
}

//When death animation is over, go back to main menu screen
Death::~Death()
{
  WorldManager &wm = WorldManager::getInstance();
 LogManager &lm = LogManager::getInstance();
  ObjectList all_objects = wm.getAllObjects();
  ObjectListIterator li(&all_objects);
  for (li.first(); !li.isDone(); li.next())
    {
      if (li.currentObject() -> getType() != "Select")
	{
	  wm.markForDelete(li.currentObject());
	}
    }
  int i = 0;
  for (li.first(); !li.isDone(); li.next())
    {
      if (li.currentObject() -> getType() == "Select")
	{
	  i++;
	}
    }

    lm.writeLog("I am before the death if statement");
  if(i == 0){
    lm.writeLog("I am in the death if statement");
    new Select;
  }
}

int Death::eventHandler(Event *p_e) {

  //Call the step function for every step
  if (p_e -> getType() == DF_STEP_EVENT) {
    step();
    return 1;
  }

  return 0;
}

//Decrease time to live for every step. After time to live is over, finish
//animation
void Death::step() {
  time_to_live--;
  if (time_to_live <= 0) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.markForDelete(this);
  }
}
