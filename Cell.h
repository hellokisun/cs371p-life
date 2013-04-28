#ifndef Cell_h
#define Cell_h

#include "Handle.h"
#include <typeinfo>

class Cell : public Handle<AbstractCell> {
	friend std::ostream& operator << (std::ostream& lhs, const Cell& rhs) {
		return lhs << *(rhs.get());
	}

	friend std::istream& operator >> (std::istream& lhs, Cell& rhs) {
		return lhs >> *(rhs.get());
	}

	private:
		bool want_to_mutate;

	public:
		Cell() : Handle<AbstractCell>(new FredkinCell(false)) {}

		Cell(AbstractCell* f) : Handle<AbstractCell>(f) {}

		virtual Cell* clone() const {
			return new Cell(*this);
		}

		virtual bool isAlive() const {
			return get()->isAlive();
		}

		virtual bool flagged() const{
			return get()->flagged();
		}

		virtual bool change() {
			return get()->change();
		}

		virtual bool mutate() {
			Handle<AbstractCell> x (new ConwayCell(true));
			swap(x);
			return true;
		}

		virtual void update(int n) {
			if(get()->update(n))
				mutate();
		}

		int code() {
			return get()->code();
		}
};

#endif