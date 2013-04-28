#include "FredkinCell.h"

FredkinCell* FredkinCell::clone() const {
	return new FredkinCell(isAlive());
}

bool FredkinCell::mutate() {
	return AbstractCell::change();
}

bool FredkinCell::update(int n) {
	if(isAlive()) {
		if(n % 2) {
			AbstractCell::setFlag(false);
			++age;
			if(age >= 2)
				return true;
		}
		else
			AbstractCell::setFlag(true);

	}
	else {
		if(n % 2)
			AbstractCell::setFlag(true);
		else
			AbstractCell::setFlag(false);
	}
	return false;
}

int FredkinCell::code() {
	return 0;
}