#include "Grid.h"
#include <iostream>
#include <string>
#include <cstring>

Grid::Grid(int _size) {
    size = _size;
    grid = new char[size * size];
    memset(grid, ' ', sizeof(char)*size*size);
}

void Grid::createGrid() {
    head = new Node();
}

void Grid::getGrid() {
    std::cout << std::endl;
    for (int y = 0; y < size; y++) {
        std::string row;
        for (int x = 0; x < size; x++) {
            char gridChar = grid[x + size*y];
            char cell[4] = {'[', gridChar, ']'};
            std::string cellString(cell);
            
            row = row + cellString;
        }

        std::cout << row << std::endl;
    }

    std::cout << std::endl;
}

void Grid::setStart(int xPos, int yPos) {
    grid[xPos + size*yPos] = '^';
    getGrid();
}

void Grid::setTarget(int xPos, int yPos) {
    grid[xPos + size*yPos] = '*';
    getGrid();
}