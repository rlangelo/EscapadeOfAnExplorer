#include "ViewObject.h"

class Select10 : public ViewObject
{

 public:
  Select10();
  int eventHandler(Event *p_e);
  void draw();
  ~Select10();
  void start();
};
