#include "Object.h"
#include "EventKeyboard.h"
#include "EventCollision.h"

class Hero : public Object
{

 private:
  void kbd(EventKeyboard *p_keyboard_event);
  void moveVertical(int dy);
  void moveHorizontal(int dx);
  void hit(EventCollision *p_collision);

 public:
  Hero();
  int eventHandler(Event *p_e);
  ~Hero();
};
