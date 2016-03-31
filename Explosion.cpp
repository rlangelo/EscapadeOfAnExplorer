/***********************************************************************************************************************************************************************************************************************************************Explosion class from Professor Claypool's Saucer Shoot Tutorial
 **************************************************************************************************/

#include "Explosion.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "EventStep.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "GameStart.h"
#include "Select.h"

Explosion::Explosion() {
  LogManager &log_manager = LogManager::getInstance();
  ResourceManager &resource_manager = ResourceManager::getInstance();

  //Setup explosion sprite
  Sprite *p_temp_sprite = resource_manager.getSprite("explosion");
  if (!p_temp_sprite) {
    log_manager.writeLog("Explosion::Explosion(): Warning! Sprite '%s' !found", "explosion");
  }
  setSprite(p_temp_sprite);
  setType("Explosion");
  registerInterest(DF_STEP_EVENT);


  //set live time as long as sprite length
  time_to_live = getSprite()->getFrameCount();

  //set solidness of explosion
  setSolidness(SPECTRAL);

}

//Once explosion animation is over, destroy all objects and go to main screen
Explosion::~Explosion()
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

   lm.writeLog("I am before the explosion if statement");
  if(i == 0){
    lm.writeLog("I am in the explosion if statement");
    new Select;
  }
}

int Explosion::eventHandler(Event *p_e) {

  //for every step call the step function
  if (p_e -> getType() == DF_STEP_EVENT) {
    step();
    return 1;
  }

  return 0;
}

//Decrease time to live for every step. After time to live is over, finish
//animation
void Explosion::step() {
  time_to_live--;
  if (time_to_live <= 0) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.markForDelete(this);
  }
}
