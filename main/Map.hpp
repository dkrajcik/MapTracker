#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Cell.hpp"

using namespace std;

class Map {
public:
	Map(string file);
	~Map();

	void printCells();

	vector<Cell*> getCellVector();

	int getSize();

private:
	int size;

	string map;
	string finalMap;

	vector <Cell*> cellVector;

	void readFile(string file);
	void cleanseMap();
	void createCellMap();
};