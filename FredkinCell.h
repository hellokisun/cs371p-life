#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"

class FredkinCell : public AbstractCell {
	private:

	protected:
		virtual bool equals (const AbstractCell& that) const {
			return (isAlive() == that.isAlive() && getSymbol() == that.getSymbol());
		}

		virtual std::istream& read (std::istream& in) {
			return AbstractCell::read(in);
		}

		virtual std::ostream& write (std::ostream& out) const {
			return AbstractCell::write(out);
		}

	public:
		FredkinCell(bool a) : AbstractCell(a){}

		virtual FredkinCell* clone() const {
			//write this method
			return new FredkinCell(*this);
		}

		virtual bool isAlive() const {
			return AbstractCell::isAlive();
		}

		virtual char getSymbol() const {
			return AbstractCell::getSymbol();
		}

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