#include "ViewObject.h"

class Select9 : public ViewObject
{

 public:
  Select9();
  int eventHandler(Event *p_e);
  void draw();
  ~Select9();
  void start();
};
