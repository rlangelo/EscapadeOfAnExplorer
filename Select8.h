#include "ViewObject.h"

class Select8 : public ViewObject
{

 public:
  Select8();
  int eventHandler(Event *p_e);
  void draw();
  ~Select8();
  void start();
};
