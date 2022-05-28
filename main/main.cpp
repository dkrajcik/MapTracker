#include <iostream>
#include "Map.hpp"
#include "Tracker.hpp"

using namespace std;


int main()
{
    //create a map from a file
    Map map("C:/Users/12629/Downloads/10x10map.txt");

    //create a tracker capable of traversing through a map
    Tracker tracker;

    //send the tracker to find a path through the map
    tracker.findPath(map);

    //print the original cells from the file
    map.printCells();

    //print an X/O map from the start to the end
    tracker.printRoute();

    return 0;
}