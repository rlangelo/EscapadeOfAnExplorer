#include "Object.h"

class Death : public Object
{

 private:
  int time_to_live;
  void step();

 public:
  Death();
  int eventHandler(Event *p_e);
  ~Death();
};
