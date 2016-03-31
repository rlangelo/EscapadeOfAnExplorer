#include "ViewObject.h"
#include "EventKeyboard.h"

class Select : public ViewObject
{

 public:
  Select();
  int eventHandler(Event *p_e);
  void draw();
  ~Select();
  void start();
  void kbd(EventKeyboard *p_key);
};
