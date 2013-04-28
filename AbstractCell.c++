#include "AbstractCell.h"
#include <iostream>

bool AbstractCell::isAlive() const {
	return alive;
}

bool AbstractCell::change() {
	alive = !alive;
	if(alive) return true;
	else return false;
}

bool AbstractCell::flagged() const{
	return flag;
}	

void AbstractCell::setFlag(bool n) {
	flag = n;
}

bool AbstractCell::update(int n) {
	return false;
}