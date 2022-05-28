#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Map.hpp"
#include "Cell.hpp"

using namespace std;

Map::Map(string file) {
    size = 0;
    map = "";
    finalMap = "";

    readFile(file);
    cleanseMap();    
    createCellMap();
}

Map::~Map() {
    for (int i = 0; i < (size*size); i++)
    {
        delete cellVector[i];
        cellVector[i] = 0;
    }
    cellVector.clear();
}

void Map::printCells() {
    for (int i = 0; i < map.length(); i++) {
        if (i % size == 0) {
            cout << endl;
        }
        cout << map[i] << ' ';
    }
    cout << endl;
}

void Map::readFile(string file){
    string input;
    ifstream openFile;
    openFile.open(file);

    while (!openFile.eof()) {
        getline(openFile, input);
        map += input;
        size++;
    }
    openFile.close();
    }

void Map::cleanseMap() {
    for (int i = 0; i < map.length(); i++) {
        if (map.at(i) == ' ') {
            map.erase(map.begin() + i);
            i--;
        }
    }
}

void Map::createCellMap() {
    int x = 0;
    int y = 0;

    for (int i = 0; i < map.length(); i++) {
        Cell* p_newCell = new Cell;

        p_newCell->type = map[i];;
        p_newCell->X = x;
        x++;

        if (x == size) {
            x = 0;
        }
        
        if (i % size == 0 && i != 0) {
            y++;
        }

        p_newCell->Y = y;
        if (i < size) {
            p_newCell->p_north = 0;
        }

        if (i % size == 0) {
            p_newCell->p_west = 0;
        }

        if (i >= (size * size) - size) {
            p_newCell->p_south = 0;
        }

        if (i % size == size - 1) {
            p_newCell->p_east = 0;
        }

        if (i > 0 && i % size != 0) {
            p_newCell->p_west = cellVector[i - 1];
        }

        if (i >= size) {
            p_newCell->p_north = cellVector[i - size];
        }
        cellVector.push_back(p_newCell);
    }
    for (int i = size*size - 1; i >= 0; i--) {
        if (i < (size * size) - size) {
            cellVector[i]->p_south = cellVector[i + size];
        }

        if (i % size != size - 1) {
            cellVector[i]->p_east = cellVector[i + 1];
        }
    }
}

vector<Cell*> Map::getCellVector() {
    return cellVector;
}

int Map::getSize() {
    return size;
}