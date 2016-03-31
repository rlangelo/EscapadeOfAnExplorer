#include "ViewObject.h"

class Select6 : public ViewObject
{

 public:
  Select6();
  int eventHandler(Event *p_e);
  void draw();
  ~Select6();
  void start();
};
