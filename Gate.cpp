#include "Gate.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "EventStep.h"
#include "Block.h"

Gate::Gate()
{
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();

  //Set up pressure gate sprite
  Sprite *p_temp_sprite;
  p_temp_sprite = rm.getSprite("gateon");

  if (!p_temp_sprite)
    {
      lm.writeLog("Gate::Gate(): Warning! Sprite '%s' !found", "gateon");}
  else {
    setSprite(p_temp_sprite);
  }

  //Set type for object and register its interest on step event
  setType("Gate");
  registerInterest(DF_STEP_EVENT);

 
}

int Gate::eventHandler(Event *p_e)
{
  //If collision event, call hit method
  if (p_e -> getType() == DF_COLLISION_EVENT)
    {
      EventCollision *p_c = static_cast <EventCollision *> (p_e);
      hit(p_c);
      return 1;
    }
  //if step event, call step method
  if (p_e -> getType() == DF_STEP_EVENT)
    {
      step();
      return 1;
    }
  return 0;
}

/* For every step, we get all of the game objects. We iterate through them and 
for each object we check to see if it's a block. If it is, we check to see if 
it's boolean "isOnPlate" is true. If it is, we increment the blocks_on_plate 
counter. If the object is not a block, we check to see if it's a plate, if it
is a plate we increment the counter number_of_plates. In the end, we check to
see if the two counters have the same value. If they do, the pressure gates
"disappear" */

void Gate::step()
{
  WorldManager &wm = WorldManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();
  LogManager &lm = LogManager::getInstance();
  ObjectList all_objects = wm.getAllObjects();
  ObjectListIterator li(&all_objects);
  int blocks_on_plate = 0;
  int number_of_plates = 0;

  for (li.first(); !li.isDone(); li.next())
    {
      if (li.currentObject() -> getType() == "Block")
	{
	  Block *p_b = static_cast <Block *> (li.currentObject());
	  if (p_b -> getOnPlate())
	    {
	      blocks_on_plate++;
	    }
	}
      else if (li.currentObject() -> getType() == "Plate")
	{
	  number_of_plates++;
	}
    }

  if (blocks_on_plate == number_of_plates)
    {
      Sprite *p_temp_sprite;
      p_temp_sprite = rm.getSprite("gateoff");

      if (!p_temp_sprite)
	{
	  lm.writeLog("Gate::Gate(): Warning! Sprite '%s' !found", "gateoff");}
      else {
	setSprite(p_temp_sprite);
      }
      setSolidness(SPECTRAL);
      setAltitude(0);
    }

  else
    {
      Sprite *p_temp_sprite;
      p_temp_sprite = rm.getSprite("gateon");

      if (!p_temp_sprite)
	{
	  lm.writeLog("Gate::Gate(): Warning! Sprite '%s' !found", "gateon");}
      else {
	setSprite(p_temp_sprite);
      }
      setSolidness(HARD);
      setAltitude(2);
    }

}
  
void Gate::hit(EventCollision *p_c)
{
  
}
