#include "Exit.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "GameStart.h"
#include "Select.h"

Exit::Exit()
{
	ResourceManager &rm = ResourceManager::getInstance();
	LogManager &lm = LogManager::getInstance();

	//Set up sprite for Exit
	Sprite *p_temp_sprite;
	p_temp_sprite = rm.getSprite("exit");

	if (!p_temp_sprite)
	{
	     lm.writeLog("Exit::Exit(): Warning! Sprite '%s' !found", "exit");
	}
	else
	{
		setSprite(p_temp_sprite);
	}

	setType("Exit");


}

int Exit::eventHandler(Event *p_e)
{
	return 1;
}

//When exit is destroyed, destroy all objects and go back to the main menu.
Exit::~Exit()
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
 lm.writeLog("I am before the exit if statement");
  if(i == 0){
     lm.writeLog("I am in the exit if statement");
    new Select;
  }
}



