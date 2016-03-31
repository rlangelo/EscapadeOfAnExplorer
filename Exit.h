#include "Object.h"
#include "EventCollision.h"

class Exit : public Object
{

	public:
		Exit();
		int eventHandler(Event *p_e);
		~Exit();
};



