#include <map>
#include <string>
#include "Node.h"

class Grid {
private:
    char *grid;
    int target[2];
    int start[2];
    int counter;
    Node* head;
    Node* startNode;

    void resetPath();
    Node* DFS(Node* node, std::map<int, bool> visited);
    Node* BFS(Node* node, std::map<int, bool> visited);
    Node* dijkstra(Node* node);
public:
    int size;

    Grid(int _size);
    Grid(std::string fileName);
    void createGrid(char* nodeInit = NULL);
    void getGrid(bool resetPath = false);
    void setValue(int xPos, int yPos, char value);
    void pathfind(int mode);
    int getSize(int _size);
};