#include "ViewObject.h"

class Select4 : public ViewObject
{

 public:
  Select4();
  int eventHandler(Event *p_e);
  void draw();
  ~Select4();
  void start();
};
