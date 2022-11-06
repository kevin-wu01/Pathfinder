#include <iostream>
#include "Grid.h"

int start[2] = {-1, -1};
int target[2] = {-1, -1};

int menuLoop() {
    int active = 1;
    int mode;

    while (active) {
        std::cout << "Menu Options" << std::endl << std::endl;
        std::cout << "0: Add Obstacles" << std::endl;
        std::cout << "1: Add Start" << std::endl;
        std::cout << "2: Add Target" << std::endl;
        std::cout << "3: Start Pathfinding" << std::endl;
        std::cin >> mode;

        if (mode < 0 || mode > 2) {
            std::cout << "Invalid value" << std::endl;
        } else if (start[0] == -1 && mode == 3) {
            std::cout << "Start must be specified" << std::endl;
        } else if (target[0] == -1 && mode == 3) {
            std::cout << "Target must be specified" << std::endl;
        } else {
            active = 0;
        }
    }

    return mode;
}

int main(int argc, char *argv[])
{
    int gridSize;

    std::cout << "Welcome to Pathfinder!" << std::endl;
    std::cout << "Please specify a grid size:" << std::endl;
    std::cin >> gridSize;
    Grid grid(gridSize);
    grid.getGrid();

    int mode = menuLoop();

    switch(mode)
    {
        case 0:
            break;
        case 1:
            std::cout << "X coordinate:" << std::endl;
            std::cin >> start[0];
            std::cout << "Y coordinate:" << std::endl;
            std::cin >> start[1];
            grid.setStart(start[0], start[1]);
            break;
        case 2:
            std::cout << "X coordinate:" << std::endl;
            std::cin >> target[0];
            std::cout << "Y coordinate:" << std::endl;
            std::cin >> target[1];
            grid.setStart(target[0], target[1]);
            break;
    }
}