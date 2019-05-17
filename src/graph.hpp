#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

// alias for the ship type
#define R 0
#define F 1
#define B 2
#define T 3

// defines a maximum grater then the maximun values of the input
#define MAX 1000000001

using namespace std;

class Displacement {
public:
	int source;
	int target;

	Displacement(const int s, const int t);

	/**
	 * Compares two displacements by source index
	 * @param  a first displacement to be compared
	 * @param  b second displacement to be compared
	 * @return true if the index of source of the first ship is lower the second
	 * 			else return false
	 */
	static bool compareSources (const Displacement& a, const Displacement& b){
		return a.source < b.source;
	}
};

class Ship {
public:
	char type;
	int start;
	int end;
	int size;

	int numberOfDisplacements = 0;
	vector<Displacement> displacements;

	Ship (const int start, const int end, const int type);
	void addDisplacement (const Displacement& displacement);

	/**
	 * Function that comparates two ships by it displacement count
	 * @param a first ship to be compared
	 * @param b second ship to be compared
	 * @return true if the number of displacements of the first ship is lower the second
	 * 			else return false
	 */
	static bool compareNumberOfDisplacements (const Ship& a, const Ship & b) {
		return a.numberOfDisplacements < b.numberOfDisplacements;
	}
};

class Graph {
public:
	int N; // number of vertices
	int M; // number of teleports (edges)
	vector<vector<int>> adj;
	vector<Ship> ships;

	// counter of ships by type
	int cFri = 0;
	int cRec = 0;
	int cTrans = 0;
	int cBom = 0;

	void fillDisplacementsOnShips(const vector<Displacement>& ts);
	void calculateShipComponents();
	void calculateAdvantageTime(const vector<Displacement>& displacements);
};

#endif
