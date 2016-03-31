#include "ViewObject.h"

class Select14 : public ViewObject
{

 public:
  Select14();
  int eventHandler(Event *p_e);
  void draw();
  ~Select14();
  void start();
};
