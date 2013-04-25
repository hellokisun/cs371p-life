#ifndef AbstractCell_h
#define AbstractCell_h

#include <iostream>


class AbstractCell { 
	friend bool operator == (const AbstractCell &lhs, const AbstractCell &rhs) {
		return lhs.equals(rhs);
	}

	friend bool operator != (const AbstractCell &lhs, const AbstractCell &rhs) {
		return !(lhs == rhs);
	}

	friend std::ostream& operator << (std::ostream& lhs, const AbstractCell& rhs) {
		return rhs.write(lhs);
	}

	friend std::istream& operator >> (std::istream& lhs, AbstractCell& rhs) {
		return rhs.read(lhs);
	}

	private:
		bool alive;
		char symbol;

	protected:
		AbstractCell& operator = (const AbstractCell& that) {
			alive = that.isAlive();
			symbol = that.symbol;
			return *this;
		}

		virtual bool equals (const AbstractCell& that) const = 0;

		virtual std::istream& read (std::istream& in) = 0;

		virtual std::ostream& write (std::ostream& out) const = 0;

	public:
		//constructor
		AbstractCell() {}

		AbstractCell(bool a) {
			alive = a;
			if(a)
				symbol = '*';
			else
				symbol = '.';
		}

		virtual ~AbstractCell() {}

		virtual bool isAlive() const {
			return alive;
		}

		virtual char getSymbol() const {
			return symbol;
		}

		virtual AbstractCell* clone() const = 0;

		virtual bool want_to_mutate() const = 0;

		virtual void mutate() = 0;

		virtual void update() = 0;



};

#endif