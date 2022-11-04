#include "Grid.h"
#include <iostream>
#include <string>
#include <cstring>

Grid::Grid(int _size) {
    size = _size;
    grid = new char[size * size];

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            grid[x + sizeof(char)*y] = ' ';
        }
    }
}

void Grid::getGrid() {
    for (int y = 0; y < size; y++) {
        std::string row;
        for (int x = 0; x < size; x++) {
            char cell[4] = "[ ]";
            std::string cellString = cell;
            if (x != size - 1) cellString = cellString + " ";
            
            row = row + cellString;
        }

        std::cout << row << std::endl;
    }
}