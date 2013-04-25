#ifndef Life_h
#define Life_h

#include <vector>
#include <fstream>
#include <iostream>
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

template <class T>
class Life {

	private:
		vector<T> _c;
		int gen, _x, _y, _p;		//_x*_y board, _p = population, gen = generation
	


	public:
		//constructor
		Life(int x, int y, T cell) : 
			_c  (x*y, cell)	{
				gen = 0;
				_x = x;
				_y = y;
				_p = 0;
		}

		void populate (ifstream& infile) {
			cout << "in populate()" << endl;
			unsigned int i = 0;
			while(i < _c.size()) {
				infile >> _c[i];
				if(_c[i].getSymbol() != '.')
					++_p;
				++i;
			}
		}

		//simulates one turn
		void simulate () {

		}

		//prints the board
		void print() {
			//print generation & population
			//Generation = 0, Population = 35.
			assert(_p >= 0);
			cout << "Generation = " << gen << ", Population = " << _p << "." << endl;

			for(int i = 0; i < _y; ++i) {
				for(int j = 0; j < _x; ++j) {
					//print symbols
					cout << _c[i*_x + j].getSymbol();
				}
				cout << endl;
			}

			cout << endl;
		}
};

#endif