#include "ViewObject.h"

class Select2 : public ViewObject
{

 public:
  Select2();
  int eventHandler(Event *p_e);
  void draw();
  ~Select2();
  void start();
};
