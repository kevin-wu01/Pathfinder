#include <iostream>
#include <fstream>
#include <string>
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
        std::cout << "3: Start Pathfinder" << std::endl;
        std::cin >> mode;

        if (mode < 0 || mode > 3) {
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

int choosePathfindAlgo() {
    int active = 1;
    int mode;

    while (active) {
        std::cout << "Pathfinder Algorithms" << std::endl << std::endl;
        std::cout << "0: DFS" << std::endl;
        std::cout << "1: BFS" << std::endl;
        std::cin >> mode;

        if (mode < 0 || mode > 1) {
            std::cout << "Invalid value" << std::endl;
        } else {
            active = 0;
        }
    }

    return mode;
}

Grid initializeGrid() {
    bool loadExisting;
    char mode;

    while (true) {
        while (true) {
            std::cout << "Load existing grid? [y/n]" << std::endl;
            std::cin >> mode;
            if (mode != 'y' && mode != 'n') {
                std::cout << "Invalid value" << std::endl;
            } else {
                loadExisting = mode == 'y';
                break;
            }
        }

        if (loadExisting) {
            std::string fileName;
            std::cout << "Please specify the path of the file:" << std::endl;
            std::cin >> fileName;

            try {
                Grid grid(fileName);
                return grid;
            } catch (...) {
                std::cout << "Invalid file path" << std::endl;
            }
        } else {
            int gridSize;
            std::cout << "Please specify a grid size:" << std::endl;
            std::cin >> gridSize;
            Grid grid(gridSize);
            grid.createGrid();

            return grid;
        }
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Welcome to Pathfinder!" << std::endl;

    Grid grid = initializeGrid();
    grid.getGrid();
    // std::cout << "Please specify a grid size:" << std::endl;
    // std::cin >> gridSize;
    // Grid grid(gridSize);
    // grid.createGrid();
    // grid.getGrid();


    while (true) {
        int mode = menuLoop();
        int pathfindMode;

        if (mode == 3) pathfindMode = choosePathfindAlgo();

        switch(mode)
        {
            case 0:
                std::cout << "X coordinate:" << std::endl;
                std::cin >> start[0];
                std::cout << "Y coordinate:" << std::endl;
                std::cin >> start[1];
                grid.setValue(start[0], start[1], '|');
                break;
            case 1:
                std::cout << "X coordinate:" << std::endl;
                std::cin >> start[0];
                std::cout << "Y coordinate:" << std::endl;
                std::cin >> start[1];
                grid.setValue(start[0], start[1], '^');
                break;
            case 2:
                std::cout << "X coordinate:" << std::endl;
                std::cin >> target[0];
                std::cout << "Y coordinate:" << std::endl;
                std::cin >> target[1];
                grid.setValue(target[0], target[1], '*');
                break;
            case 3:
                grid.pathfind(pathfindMode);
                break;
        }
    }
}
