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

	Teleport(int s, int t);
	bool operator < (Teleport const & other){
		return source < other.source;
	}
};

class Ship {
public:
	int start;
	int end;
	int size;
	char type;

	int minTeleports = 0;
	vector<Teleport> teleports;

	Ship(int s, int e, int t);
	bool operator < (Ship & other);
	void addTeleport (Teleport t);
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

	void fillTeleports (vector<Teleport> ts);
	void calculateShips ();
	void calculateDistances (vector<Teleport> teleports);
};

#endif
