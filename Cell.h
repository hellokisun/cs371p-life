#ifndef Cell_h
#define Cell_h

#include "Handle.h"

class Cell : public Handle<AbstractCell> {
	private:
		AbstractCell* _ac;

	public:
		Cell(AbstractCell* ac) : 
			Handle(*this) {_ac = ac;}
};

#endif