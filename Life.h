#ifndef Life_h
#define Life_h

#include <vector>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

template <class T>
class Life {

	private:
		vector<vector<T> > _c;
		int gen, _x, _y, _p;		//_x*_y board, _p = population, gen = generation
	


	public:
		//constructor. vector is 2 sizes bigger than actual game size (for edge cases)
		Life(int x, int y, T cell) : 
			_c  (y+2, vector<T> (x+2, cell))	{
				gen = 0;
				_x = x+2;
				_y = y+2;
				_p = 0;
		}

		void populate (ifstream& infile) {
			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					infile >> _c[i][j];
					if(_c[i][j].isAlive()) {
						++_p;
						// _c[i][j].change();
					}
				}
			}
		}

		//simulates one turn
		void simulate () {
			//look at all cells (for now)
			//see if they need to mutate/die/come alive
			//mark toMutate if they need to change
			//after going through everything, go through once again and mutate those marked with toMutate

			++gen;
			int tc;
			// cout << typeid(_c[1][1]).name() << endl;
			for(int i = 1; i < _y-1; ++i) {

				for(int j = 1; j < _x-1; ++j) {
					tc = 0;
					//check neighbors
					if(_c[i-1][j-1].isAlive())
						++tc;
					if(_c[i-1][j].isAlive())
						++tc;
					if(_c[i-1][j+1].isAlive())
						++tc;
					if(_c[i][j-1].isAlive())
						++tc;
					if(_c[i][j+1].isAlive())
						++tc;
					if(_c[i+1][j-1].isAlive())
						++tc;
					if(_c[i+1][j].isAlive())
						++tc;
					if(_c[i+1][j+1].isAlive())
						++tc;

					//update toMutate
					_c[i][j].update(tc);
					// if(tc > 0)
					// 	cout << "(" << j << ", " << i << ") : tc=" << tc << "; mutate? " << _c[i][j].want_to_mutate() << endl;

				}

			}

			//mutate
			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					if(_c[i][j].want_to_mutate())
						_c[i][j].mutate();
				}
			}
		}

		//prints the board
		void print() {
			//print generation & population
			//Generation = 0, Population = 35.
			assert(_p >= 0);
			cout << "Generation = " << gen << ", Population = " << _p << "." << endl;

			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					//print symbols
					//TODO change this from getSymbol (get rid of the getter method) and into something like print() 
					//to print directly to cout. also consider getting rid of the symbol variable and making print()
					//decide what the symbol to be printed will be (for conway, dead = '.' and alive = '*', no need
					//to keep the extra variable that is unnecessary. for fredkin, it should be the same concept since
					//there will be a separate variable for age).
					if(_c[i][j].isAlive())
						cout << _c[i][j];
					else
						cout << '.';
				}
				cout << endl;
			}

			cout << endl;
		}
};

#endif