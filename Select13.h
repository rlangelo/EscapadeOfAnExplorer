#include "ViewObject.h"

class Select13 : public ViewObject
{

 public:
  Select13();
  int eventHandler(Event *p_e);
  void draw();
  ~Select13();
  void start();
};
