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

			//TODO make this work for both Conway and Fredkin

			//for ConwayCell
			// if (const T* const p = dynamic_cast<const ConwayCell*>(&_c[0][0])) {
			if(typeid(T) == typeid(ConwayCell)) {
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
			}

			// for FredkinCell
			else if(typeid(T) == typeid(FredkinCell)) {
				for(int i = 1; i < _y-1; ++i) {
					for(int j = 1; j < _x-1; ++j) {
						tc = 0;
						//do stuff
						if(_c[i-1][j].isAlive())
							++tc;
						if(_c[i][j-1].isAlive())
							++tc;
						if(_c[i][j+1].isAlive())
							++tc;
						if(_c[i+1][j].isAlive())
							++tc;

						_c[i][j].update(tc);
					}
				}
			}

			//for Cell



			//mutate
			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					if(_c[i][j].want_to_mutate()) {
						if(_c[i][j].change())
							++_p;
						else --_p;
					}
				}
			}
		}

		//prints the board
		void print() {
			//print generation & population
			assert(_p >= 0);
			cout << "Generation = " << gen << ", Population = " << _p << "." << endl;

			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					cout << _c[i][j];
				}
				cout << endl;
			}

			cout << endl;
		}
};

#endif