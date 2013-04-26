#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	private:

	protected:
		virtual bool equals (const AbstractCell& that) const {
			return (isAlive() == that.isAlive());
		}

		virtual std::istream& read (std::istream& in) {
			return AbstractCell::read(in);
		}

		// virtual std::ostream& write (std::ostream& out) const {
		// 	return AbstractCell::write(out);
		// }

	public:
		ConwayCell(bool a) : AbstractCell(a){}

		virtual ConwayCell* clone() const {
			//write this method
			return new ConwayCell(*this);
		}

		virtual bool isAlive() const {
			return AbstractCell::isAlive();
		}

		// virtual char getSymbol() const {
		// 	return AbstractCell::getSymbol();
		// }

		// virtual bool want_to_mutate() const {
		// 	return AbstractCell::want_to_mutate();
		// }

		virtual void mutate() {
			AbstractCell::change();
		}

		virtual void update(int n) {
			//write this method
			if(isAlive()) {
				if(n < 2 || n > 3)
					AbstractCell::update(true);
				else
					AbstractCell::update(false);

			}
			else {
				if(n == 3)
					AbstractCell::update(true);
				else
					AbstractCell::update(false);
			}
		}
};

#endif