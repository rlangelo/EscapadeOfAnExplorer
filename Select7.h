#include "ViewObject.h"

class Select7 : public ViewObject
{

 public:
  Select7();
  int eventHandler(Event *p_e);
  void draw();
  ~Select7();
  void start();
};
