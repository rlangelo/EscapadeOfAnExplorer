#include "Bomb.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"

Bomb::Bomb()
{
	ResourceManager &rm = ResourceManager::getInstance();
	LogManager &lm = LogManager::getInstance();
	
	//Load the sprite for bombs
	Sprite *p_temp_sprite;
	p_temp_sprite = rm.getSprite("bomb");
	if (!p_temp_sprite)
	{
		lm.writeLog("Bomb::Bomb(): Sprite '%s' not found", "bomb");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	//set the type for the object
	setType("Bomb");
	

}

int Bomb::eventHandler(Event *p_e)
{
	return 1;
}
