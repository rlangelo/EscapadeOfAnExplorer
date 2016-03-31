#include "ViewObject.h"

class Select12 : public ViewObject
{

 public:
  Select12();
  int eventHandler(Event *p_e);
  void draw();
  ~Select12();
  void start();
};
