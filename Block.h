#include "Object.h"
#include "EventCollision.h"

class Block : public Object
{
 public:
  Block();
  int eventHandler(Event *p_e);
  bool isOnPlate;
  void setOnPlate(bool onPlate);
  bool getOnPlate();
  void hit(EventCollision *p_c);
  void chooseSprite(bool onPlate);
  void moveHorizontal(int dx);
  void moveVertical(int dy);
  void step();
};
