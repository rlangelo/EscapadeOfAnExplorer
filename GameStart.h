#include "ViewObject.h"

class GameStart : public ViewObject
{
	public:
	 void draw();
         GameStart();
	 ~GameStart();
         int eventHandler(Event *p_e);
	 void start();
};


