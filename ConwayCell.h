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

		virtual std::ostream& write (std::ostream& out) const {
			if(isAlive())
				return out << '*';
			else
				return out << '.';
		}

	public:
		ConwayCell(bool a) : AbstractCell(a){}

		virtual ConwayCell* clone() const {
			//TODO write this method
			return new ConwayCell(*this);
		}

		// virtual bool isAlive() const {
		// 	return AbstractCell::isAlive();
		// }

		virtual void mutate() {
			AbstractCell::change();
		}

		virtual void update(int n) {
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