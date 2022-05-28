#pragma once
#include <iostream>
#include <vector>
#include "Stack.hpp"
#include "Map.hpp"
#include "Cell.hpp"

using namespace std;

class Tracker {
public:
	Tracker();
	void printRoute();
	void findPath(Map &map);

private:
	bool checkForRoute();
	Cell* p_current;
	Stack<Cell*> route;
	int size;
	string returnMap;
	vector <Cell*> cells;
};
