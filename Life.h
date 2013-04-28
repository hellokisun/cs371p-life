/**


*/


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


/*
Simulates the game of Life on a two dimensional grid. There are two types of cells:
	ConwayCell	- 	This cell is either alive or dead, represented by '*' or '.', respectively.
					It has 8 neighbors (all adjacent cells, including diagonal).
	FredkinCell	- 	This cell is either alive or dead, but also keeps count of how long it
					has been alive for. It is represented by its age (0, 1, ... 9). If its
					age is over 9, then it is represented by '+'. Dead cells are represented
					with a '-'. It has 4 neighbors (no diagonal adjacency).
These two types of cells can change their state (alive to dead and vice versa) every "generation"
(turn). 
For ConwayCells,	
		a dead cell becomes a live cell, if exactly 3 neighbors are alive
		a live cell becomes a dead cell, if less than 2 or more than 3 neighbors are alive
For FredkinCells,
		a dead cell becomes a live cell, if 1 or 3 neighbors are alive
		a live cell becomes a dead cell, if 0, 2, or 4 neighbors are alive
(Taken from project specs page)
*/

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
				if(cell.isAlive())
					_p = x*y;
				else
					_p = 0;

		}

		//populates the game. 
		//@param infile the input files if the user chooses to use a file to populate the board.
		void populate (ifstream& infile) {
			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					infile >> _c[i][j];
					if(_c[i][j].isAlive()) {
						++_p;
					}
				}
			}
		}

		void setCell(int x, int y) {
			++_p;
			_c[y+1][x+1].change();
		}

		//simulates one turn
		void simulate () {
			//look at all cells (for now)
			//see if they need to mutate/die/come alive
			//mark flag if they need to change
			//after going through everything, go through once again and change the state of those marked with flag

			++gen;
			int tc;

			//for ConwayCell
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
			else if(typeid(T) == typeid(Cell)) {
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
						//do stuff if the cell is ConwayCell
						if(_c[i][j].code()) {
							if(_c[i-1][j-1].isAlive())
								++tc;
							if(_c[i-1][j+1].isAlive())
								++tc;
							if(_c[i+1][j-1].isAlive())
								++tc;
							if(_c[i+1][j+1].isAlive())
								++tc;
						}

						_c[i][j].update(tc);
					}
				}

			}

			//mutate
			for(int i = 1; i < _y-1; ++i) {
				for(int j = 1; j < _x-1; ++j) {
					if(_c[i][j].flagged()) {
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
			// assert(_p >= 0);
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