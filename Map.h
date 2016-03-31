#include "Object.h"
#include "Event.h"
#include <string.h>

using std::string;

class Map : public Object
{
 public:
  Map(int levelNumber);
  int loadMap(string filename);
  int levelCounter;
  void setLevelCounter(int new_counter);
  int getLevelCounter();
};

