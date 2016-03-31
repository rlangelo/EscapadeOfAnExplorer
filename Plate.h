#include "Object.h"
#include "EventCollision.h"

class Plate : public Object
{
	public:
		Plate();
		int eventHandler(Event *p_e);
	       
};
