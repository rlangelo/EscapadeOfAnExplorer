#include "ViewObject.h"

class Tutorial : public ViewObject
{
 public:
  Tutorial(int levelNumber);
  void draw();
  int eventHandler(Event *p_e);
  ~Tutorial();
};
