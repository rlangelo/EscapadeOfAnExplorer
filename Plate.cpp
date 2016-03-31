#include "Plate.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventCollision.h"

Plate::Plate()
{
	ResourceManager &rm = ResourceManager::getInstance();
	LogManager &lm = LogManager::getInstance();

	//Set up pressure plate sprite
	Sprite *p_temp_sprite;
	p_temp_sprite = rm.getSprite("plate");

	if (!p_temp_sprite)
    	{
      		lm.writeLog("Plate::Plate(): Warning! Sprite '%s' !found", "plate");
   	 }
 	 else {
    		setSprite(p_temp_sprite);
 	 }

	//Set type, solidness and altitude
	setType("Plate");
	setSolidness(SOFT);
	setAltitude(0);

}

int Plate::eventHandler(Event *p_e)
{
	return 1;
}




		



