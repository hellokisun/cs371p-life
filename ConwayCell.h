#ifndef ConwayCell_h
#define ConwayCell_h

#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
	private:

	protected:
		virtual std::istream& read (std::istream& in) {
			char c;
			in >> c;
			if(c != '.') change();
			return in;
		}

		virtual std::ostream& write (std::ostream& out) const {
			if(isAlive())
				return out << '*';
			else
				return out << '.';
		}

	public:
		ConwayCell(bool a) : AbstractCell(a){}

		virtual ConwayCell* clone() const;

		virtual bool mutate();

		virtual bool update(int n);

		int code();
};

#endif