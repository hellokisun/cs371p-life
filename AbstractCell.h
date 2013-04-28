#ifndef AbstractCell_h
#define AbstractCell_h

#include <iostream>


class AbstractCell { 

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

		virtual std::istream& read (std::istream& in) = 0;

		virtual std::ostream& write (std::ostream& out) const = 0;

	public:
		//constructor
		AbstractCell(bool a) {
			flag = false;
			alive = a;
		}

		virtual ~AbstractCell() {}

		virtual bool isAlive() const;

		virtual AbstractCell* clone() const = 0;

		//returns 	true if dead -> alive
		//			false if alive -> dead
		virtual bool change();

		virtual bool flagged() const;

		virtual bool mutate() = 0;

		//n = number of alive neighbors
		virtual void setFlag(bool n);

		virtual bool update(int n);

		virtual int code() = 0;
};

#endif