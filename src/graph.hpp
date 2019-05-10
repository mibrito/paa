#ifndef GRAPH_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define GRAPH_HPP

#include <map>
#include <vector>
#include <list>

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

// void allShips (vector<vector<int>> adj, vector<array<int, 2>>& components);
// void calculateDistances (vector<vector<int>> adj, vector<array<int, 2>> components, vector<array<int, 2>> teleports);
void calculateTeleports (vector<vector<int>> adj, vector<array<int, 2>>& teleports, vector<array<int, 3>> components);

#endif
