#include "Object.h"
#include "EventCollision.h"

class Gate : public Object
{

 public:
  Gate();
  int eventHandler(Event *p_e);
  void hit(EventCollision *p_c);
  void step();
};
