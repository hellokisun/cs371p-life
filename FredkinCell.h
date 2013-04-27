#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"

class FredkinCell : public AbstractCell {
	private:
		int age;

	protected:
		virtual bool equals (const AbstractCell& that) const {
			return (isAlive() == that.isAlive());
		}

		virtual std::istream& read (std::istream& in) {
			return AbstractCell::read(in);
		}

		virtual std::ostream& write (std::ostream& out) const {
			if(isAlive()) {
				if(age >= 10)
					return out << '+';
				else
					return out << age;
			}
			else
				return out << '-';
		}

	public:
		FredkinCell(bool a) : AbstractCell(a){
			age = 0;
		}

		virtual FredkinCell* clone() const {
			//TODO write this method
			return new FredkinCell(*this);
		}

		// virtual bool isAlive() const {
		// 	return AbstractCell::isAlive();
		// }

		virtual void mutate() {
			//write this method
			AbstractCell::change();
		}

		virtual void update(int n) {
			//write this method
			//if alive, then increment age
			if(isAlive()) {
				if(n % 2) {
					AbstractCell::update(false);
					++age;
				}
				else
					AbstractCell::update(true);

			}
			else {
				if(n % 2)
					AbstractCell::update(true);
				else
					AbstractCell::update(false);
			}
		}
};

#endif