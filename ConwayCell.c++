#include "ConwayCell.h"

ConwayCell* ConwayCell::clone() const {
	return new ConwayCell(isAlive());
}

bool ConwayCell::mutate() {
	return AbstractCell::change();
}

bool ConwayCell::update(int n) {
	if(isAlive()) {
		if(n < 2 || n > 3)
			AbstractCell::setFlag(true);
		else
			AbstractCell::setFlag(false);

	}
	else {
		if(n == 3)
			AbstractCell::setFlag(true);
		else
			AbstractCell::setFlag(false);
	}
	return false;
}

int ConwayCell::code() {
	return 1;
}