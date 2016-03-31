#include "Object.h"
#include "EventCollision.h"

class Bomb : public Object
{
	public:
		Bomb();
		int eventHandler(Event *p_e);
};
