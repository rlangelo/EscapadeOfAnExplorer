//Engine includes
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

//Game includes
#include "Map.h"
#include "Hero.h"
#include "Block.h"
#include "Exit.h"
#include "Wall.h"
#include "Bomb.h"
#include "Water.h"
#include "Dirt.h"
#include "Plate.h"
#include "Gate.h"
#include "Tutorial.h"

//C++ includes
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

//Prevent every use of string/ifstream from needing a std:: prefce
using std::string;
using std::ifstream;

Map::Map(int levelNumber){

  setType("Map");

  string str;
  if (levelNumber == 1)
    {
      str = "map1.txt";
    }
  else if(levelNumber == 2)
    {
      str = "map2.txt";
    }
  else if(levelNumber == 3)
    {
      str = "map3.txt";
    }
  else if(levelNumber == 4)
    {
      str = "map4.txt";
    }
  else if(levelNumber == 5)
    {
      str = "map5.txt";
    }
  else if(levelNumber == 6)
    {
      str = "map6.txt";
    }
  else if(levelNumber == 7)
    {
      str = "map7.txt";
    }
  else if(levelNumber == 8)
    {
      str = "map8.txt";
    }
  else if(levelNumber == 9)
    {
      str = "map9.txt";
    }
  else if(levelNumber == 10)
    {
      str = "map10.txt";
    }
  else if(levelNumber == 11)
    {
      str = "map11.txt";
    }
  else if(levelNumber == 12)
    {
      str = "map12.txt";
    }
  else if(levelNumber == 13)
    {
      str = "map13.txt";
    }
  else if(levelNumber == 14)
    {
      str = "map14.txt";
    }
  loadMap(str);

  new Tutorial(levelNumber);

}

void Map::setLevelCounter(int new_counter)
{
  new_counter = levelCounter;
}

int Map::getLevelCounter()
{
  return levelCounter;
}

int Map::loadMap(string filename){
  WorldManager &wm = WorldManager::getInstance();
  LogManager &lm = LogManager::getInstance();  //Instance required managers
  Position pos;
  Object *p_o;
  ifstream mapfile;  //Declare required variables
  int xwrite = 0;
  int ywrite = 0;
  int xmax;
  int ymax;
  int xoffset;
  int yoffset;  //Position calculating variables
  string currLine;  
  char currChar;  //Read/write variables
  
  ObjectList all_objects = wm.getAllObjects();
  ObjectListIterator li(&all_objects);
  for (li.first(); !li.isDone(); li.next())
    {
      wm.markForDelete(li.currentObject());
    }

  mapfile.open(filename.c_str());  //Open the map file

  getline(mapfile, currLine);  //Read the first line (Width = #)
  lm.writeLog("Line 1: '%s'", currLine.c_str());
  xmax = atoi(currLine.substr(7, (currLine.length()-7)).c_str()); //Discard the "Width = "
  
  getline(mapfile, currLine);  //Read the second line (Height = #)
  lm.writeLog("Line 2: '%s'", currLine.c_str());
  ymax = atoi(currLine.substr(8, (currLine.length()-8)).c_str()); //Discard the "Height = "
  
  xoffset = wm.getBoundary().getHorizontal()/2 - xmax/2;  //Center the map in the viewing area
  yoffset = wm.getBoundary().getVertical()/2 - ymax/2;
  
  for (ywrite = 0; ywrite < ymax; ywrite++){  //Iterate through the map for as many lines as there are
	getline(mapfile, currLine); //read a line of the file
    for (xwrite = 0; xwrite < xmax; xwrite++){  //Iterate through the line for as many characters as there are
	  currChar = currLine[xwrite];  //Cycle through the line
          pos.setX(xwrite+xoffset);  //Write near the center of the screen
          pos.setY(ywrite+yoffset);
	  switch(currChar){  //Create the corresponding object(s) and set its position in the game
	    	case '#':
		  p_o = new Wall();
		  p_o->setPosition(pos);
		  break;
		case 'S':
		  p_o = new Hero();
		  p_o->setPosition(pos);
		  break;
		case 'B':
		  p_o = new Block();
		  p_o->setPosition(pos);
		  break;
		case 'X':
		  p_o = new Exit();
		  p_o->setPosition(pos);
		  break;
		case 'D':
		  p_o = new Dirt();
		  p_o->setPosition(pos);
		  break;
		case '~':
		  p_o = new Water();
		  p_o->setPosition(pos);
		  break;
		case 'b':
		  p_o = new Bomb();
		  p_o->setPosition(pos);
		  break;
		case 'o':
		  p_o = new Plate();
		  p_o->setPosition(pos);
		  break;
		case '|':
		  p_o = new Gate();
		  p_o->setPosition(pos);
		  break;
		case 'P':  //Block on Pressure Plate
		  p_o = new Plate();
		  p_o->setPosition(pos);
		  p_o = new Block();
		  p_o -> setPosition(pos);
		  break;
		default:
		  break;
	  }
	}
  }
  return 0;
}
