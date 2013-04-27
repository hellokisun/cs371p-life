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
		bool flag;
	protected:
		AbstractCell& operator = (const AbstractCell& that) {
			alive = that.isAlive();
			return *this;
		}

		virtual bool equals (const AbstractCell& that) const = 0;

		virtual std::istream& read (std::istream& in) = 0;

		virtual std::ostream& write (std::ostream& out) const = 0;

	public:
		//constructor
		// AbstractCell() {}

		AbstractCell(bool a) {
			flag = false;
			alive = a;
		}

		virtual ~AbstractCell() {}

		virtual bool isAlive() const {
			return alive;
		}

		virtual AbstractCell* clone() const = 0;

		//returns 	true if dead -> alive
		//			false if alive -> dead
		virtual bool change() {
			alive = !alive;
			if(alive) return true;
			else return false;
		}

		virtual bool want_to_mutate() const{
			return flag;
		}

		virtual void mutate() = 0;

		//n = number of alive neighbors
		virtual void update(bool n) {
			flag = n;
		}



};

#endif