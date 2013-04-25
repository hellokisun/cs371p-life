#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	private:

	protected:
		virtual bool equals (const AbstractCell& that) const {
			return (AbstractCell::isAlive() == that.isAlive() && AbstractCell::getSymbol() == that.getSymbol());
		}

		virtual std::istream& read (std::istream& in) {
			return AbstractCell::read(in);
		}

		virtual std::ostream& write (std::ostream& out) const {
			return AbstractCell::write(out);
		}

	public:
		ConwayCell(bool a) : AbstractCell(a){}

		virtual ConwayCell* clone() const {
			//write this method
			return new ConwayCell(*this);
		}

		// virtual bool isAlive() const {
		// 	return AbstractCell::isAlive();
		// }

		// virtual char getSymbol() const {
		// 	return AbstractCell::getSymbol();
		// }

		virtual bool want_to_mutate() const {
			//write this method
			return false;
		}

		virtual void mutate() {
			//write this method
		}

		virtual void update() {
			//write this method
		}
};

#endif