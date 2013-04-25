#include "AbstractCell.h"
#include <iostream>


bool AbstractCell::equals (const AbstractCell& that) const {
    return (alive == that.alive) && (symbol == that.symbol);}

std::istream& AbstractCell::read (std::istream& in) {
    return in >> symbol;}

std::ostream& AbstractCell::write (std::ostream& out) const {
    return out << symbol;}
