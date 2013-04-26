#include "AbstractCell.h"
#include <iostream>


bool AbstractCell::equals (const AbstractCell& that) const {
    return alive == that.alive;}

std::istream& AbstractCell::read (std::istream& in) {
	char c;
	in >> c;
	if(c == '.' || c == '-')
		alive = false;
	else
		alive = true;
    return in;}

// std::ostream& AbstractCell::write (std::ostream& out) const {
//     return out << symbol;}
