#include "Node.h"

class Grid {
private:
    char *grid;
    int target[2];
    int start[2];
    Node head;

public:
    int size;

    Grid(int _size);
    void createGrid();
    void getGrid();
    void setStart(int xPos, int yPos);
    void setTarget(int xPos, int yPos);
};