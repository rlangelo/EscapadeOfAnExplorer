#include "ViewObject.h"

class Select3 : public ViewObject
{

 public:
  Select3();
  int eventHandler(Event *p_e);
  void draw();
  ~Select3();
  void start();
};
