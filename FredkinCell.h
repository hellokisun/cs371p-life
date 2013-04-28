#ifndef FredkinCell_h
#define FredkinCell_h

#include "AbstractCell.h"

class FredkinCell : public AbstractCell {
	private:
		int age;

	protected:
		virtual std::istream& read (std::istream& in) {
			char c;
			in >> c;
			if(c != '-') change();
			return in;
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

		virtual FredkinCell* clone() const;

		virtual bool mutate();

		virtual bool update(int n);

		int code();
};

#endif