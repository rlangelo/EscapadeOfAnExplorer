#include "ViewObject.h"

class Select5 : public ViewObject
{

 public:
  Select5();
  int eventHandler(Event *p_e);
  void draw();
  ~Select5();
  void start();
};
