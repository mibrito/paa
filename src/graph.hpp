#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

#define WHITE -1
#define GREY -2
#define BLACK -3

#define R 0
#define F 1
#define B 2
#define T 3

#define MAX 1000000001

using namespace std;

class Teleport {
public:
	int source;
	int target;

	Teleport(const int s, const int t);

	/**
	 * [Ship  description]
	 * @param start [description]
	 * @param end   [description]
	 * @param type  [description]
	 */
	static bool compareSources (const Teleport& a, const Teleport& b){
		return a.source < b.source;
	}
};

class Ship {
public:
	char type;
	int start;
	int end;
	int size;

	int numberOfTeleports = 0;
	vector<Teleport> teleports;

	Ship (const int start, const int end, const int type);
	void addTeleport (const Teleport& teleport);

	/**
	 * [Ship::addTeleport  description]
	 * @param teleport [description]
	 */
	static bool compareNumberOfTeleports (const Ship& a, const Ship & b) {
		return a.numberOfTeleports < b.numberOfTeleports;
	}
};

class Graph {
public:
	vector<vector<int>> adj;
	vector<Ship> ships;

	// counter of ships by type
	int cFri = 0;
	int cRec = 0;
	int cTrans = 0;
	int cBom = 0;

	void addTeleportsOnShips (const vector<Teleport>& ts);
	void calculateShips ();
	void calculateAdvantageTime (const vector<Teleport>& teleports);
};

#endif
