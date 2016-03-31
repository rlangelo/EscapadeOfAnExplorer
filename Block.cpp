#include "Block.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "Plate.h"
#include "Dirt.h"

Block::Block()
{

  //Set Object Type
  setType("Block");

  //set the boolean to false to start with
  isOnPlate = false;

  //Load Sprite
  chooseSprite(isOnPlate);

  //Register for step event
  registerInterest(DF_STEP_EVENT);
  


}

int Block::eventHandler(Event *p_e)
{
  //If the event is a collision event... 	
	if (p_e->getType() == DF_COLLISION_EVENT)
	{
		EventCollision *p_collision = static_cast <EventCollision *> (p_e);	
	       
		//...call the hit function
			hit(p_collision);
		
		return 1;
	}

	//If it is a step event...
	if (p_e->getType() == DF_STEP_EVENT)
	  {
	    //...call the step function
	    step();
	    return 1;
	  }
	
	return 0;

}

//Getter and Setter for the isOnPlate boolean
void Block::setOnPlate(bool OnPlate)
{
	isOnPlate = OnPlate;
}

bool Block::getOnPlate()
{
	return isOnPlate;
}

//Step function
void Block::step()
{
  WorldManager &wm = WorldManager::getInstance();
  ObjectList all_colliding = wm.isCollision(this, this->getPosition());
  ObjectListIterator li(&all_colliding);
  //for every object colliding with this block...
  for (li.first(); !li.isDone(); li.next())
    {
      //if it's a plate...
      if (li.currentObject() -> getType() == "Plate")
	{
	  isOnPlate = true;
	  //change sprite
	  chooseSprite(isOnPlate);
	  return;
	}
    }
  isOnPlate = false;
  chooseSprite(isOnPlate);
}

//Block color is set depending on whether or not it's on a plate
void Block::chooseSprite(bool onPlate)
{
	ResourceManager &rm = ResourceManager::getInstance();
	if (!onPlate)
	{
		Sprite *p_temp_sprite;
		p_temp_sprite = rm.getSprite("blockoff");
		setSprite(p_temp_sprite);
	}
	else
	{
		Sprite *p_temp_sprite;
 		p_temp_sprite = rm.getSprite("blockon");
		setSprite(p_temp_sprite);
	}
	
}


//Collision function for blocks	
void Block::hit(EventCollision *p_c)
{

	ResourceManager &rm = ResourceManager::getInstance();
	WorldManager &wm = WorldManager::getInstance();

	//Block and water
	if ((p_c -> getObject1() -> getType() == "Water") &&
		 (p_c -> getObject2() -> getType() == "Block"))
	  {
	    wm.markForDelete(p_c -> getObject2());
	    wm.markForDelete(p_c -> getObject1());
	    Dirt *p_d = new Dirt;
	    p_d -> setPosition(p_c -> getObject1() -> getPosition());
	  }

	else if ((p_c -> getObject1() -> getType() == "Block") &&
		 (p_c -> getObject2() -> getType() == "Water"))
	  {
	    wm.markForDelete(p_c -> getObject2());
	    wm.markForDelete(p_c -> getObject1());
	    Dirt *p_d = new Dirt;
	    p_d -> setPosition(p_c -> getObject2() -> getPosition());
	  }

	//Block and Bomb
	else if ((p_c -> getObject1() -> getType() == "Bomb") &&
		 (p_c -> getObject2() -> getType() == "Block"))
	  {
	    wm.markForDelete(p_c -> getObject1());
	    wm.markForDelete(p_c -> getObject2());
	  }

	else if ((p_c -> getObject1() -> getType() == "Block") &&
		 (p_c -> getObject2() -> getType() == "Bomb"))
	  {
	    wm.markForDelete(p_c -> getObject2());
	    wm.markForDelete(p_c -> getObject1());
	  }
       
       
}	




