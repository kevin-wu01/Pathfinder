#include <iostream>
#include "Grid.h"

int main(int argc, char *argv[])
{
    int gridSize;
    int active = 1;

    while(active) {
        std::cout << "Hello, welcome to Pathfinder!" << std::endl;
        std::cout << "Please specify a grid size:" << std::endl;
        std::cin >> gridSize;
        Grid grid(gridSize);
        grid.getGrid();
    }
}