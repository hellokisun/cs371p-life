#include "AbstractCell.h"
#include <iostream>


// bool AbstractCell::equals (const AbstractCell& that) const {
//     return alive == that.alive;}

// std::istream& AbstractCell::read (std::istream& in) {
//     return in;}

// std::ostream& AbstractCell::write (std::ostream& out) const {
//     return out << symbol;}


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