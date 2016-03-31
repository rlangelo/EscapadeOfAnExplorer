#include "Object.h"
#include "EventCollision.h"

class Wall : public Object
{

 public:
  Wall();
  int eventHandler(Event *p_e);
};
