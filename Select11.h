#include "ViewObject.h"

class Select11 : public ViewObject
{

 public:
  Select11();
  int eventHandler(Event *p_e);
  void draw();
  ~Select11();
  void start();
};
