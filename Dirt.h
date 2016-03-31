#include "Object.h"
#include "EventCollision.h"

class Dirt : public Object
{
 public:
  Dirt();
  int eventHandler(Event *p_e);
};
