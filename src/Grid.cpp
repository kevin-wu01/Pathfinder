#include "Grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h> 
#include <unordered_set>
#include <algorithm>
#include <map>
#include <list>
#include <climits>

Grid::Grid(int _size) {
    size = _size;
    grid = new char[size * size];
    memset(grid, ' ', sizeof(char)*size*size);
}

Grid::Grid(std::string fileName) {
    std::cout << "fileName: " << fileName << std::endl;
    std::ifstream savedFile;
    savedFile.open("./src/saved.txt");
    std::string row;
    std::cout << "here" << std::endl;
    if (savedFile) {
        getline(savedFile, row);
        int size = row.length();

        char* nodeInit = new char[size*size];

        for (int i = 0; i < size; i++) {
            nodeInit[size*i] = row[i];
        }

        int x = 1;
        while (getline(savedFile, row)) {
            for (int y = 0; y < size; y++) {
                nodeInit[x + size*y] = row[y];
            }

            x++;
        }

        savedFile.close();
        createGrid(nodeInit);
    } else {
        throw std::invalid_argument("invalid file name");
    }
}

void Grid::createGrid(char* nodeInit) {
    // static const int gridSize = getSize(size);
    // Node* n = new Node();
    // Node* prevX;
    // Node* prevY;
    // Node* nextX;
    // Node* nextY;
    // Node* curr;
    // head = n;
    // int rowSize = sqrt(size);
    // int max = size - 1;
    Node** nodeGrid = new Node*[size * size];
    int counter = 1;

    // int x, y = 0;

    for (int x=0; x < size; x++) {
        for (int y=0; y < size; y++) {
            Node* n = new Node(counter);
            counter++;
            if (nodeInit != NULL) n->val = nodeInit[x + size*y];
            nodeGrid[x + size*y] = n;
        }
    }

    for (int x=0; x < size; x++) {
        for (int y=0; y < size; y++) {
            Node* n = nodeGrid[x + size*y];
            if (x != 0) n->neighbors.push_back(nodeGrid[x - 1 + size*y]);
            if (y != 0) n->neighbors.push_back(nodeGrid[x + size*(y-1)]);
            if (x != size - 1) n->neighbors.push_back(nodeGrid[x + 1 + size*y]);
            if (y != size - 1) n->neighbors.push_back(nodeGrid[x + size*(y+1)]);
        }
    }

    head = nodeGrid[0];
}

int Grid::getSize(int _size) {
    return _size;
}

// void Grid::addNode(Node* curr) {
//     Node* nextX;
//     Node* nextY;
//     int rowSize = sqrt(size);

//     if (curr->val < size - rowSize) {
//         nextY = new Node(curr->val + rowSize);
//         curr->neighbors.push_back(nextY);
//     }
//     if (curr->val < size) {
//         nextX = new Node(curr->val + 1);
//         curr->neighbors.push_back(nextX);
//     }
// } 

void Grid::getGrid(bool resetPath) {
    std::unordered_set<int> visited;
    std::cout << std::endl;
    Node* curr = head;
    int count = 0;
    int rowCount = 0;
    std::string row = "";

    while(curr != NULL) {
        Node* minNode = NULL;
        count++;
        visited.insert(curr->position);
        // 
        for (auto itr = curr->neighbors.begin(); itr != curr->neighbors.end(); itr++) {
            if (visited.find((*itr)->position) == visited.end()) {
                if (minNode != NULL) {
                    minNode = minNode->position < (*itr)->position ? minNode : (*itr);
                } else {
                    minNode = (*itr);
                }
            }
        };

        if (resetPath && curr->val == '.') curr->val = ' ';

        char cell[4] = {'[', curr->val, ']'};
        std::string cellString(cell);

        if (rowCount % 2 == 0) {
            row = row + cellString;
        } else {
            row = cellString + row;
        }
        // row = cellString + row;
        // row = row + cellString;

        if (count == size) {
            std::cout << row << std::endl;
            row = "";
            count = 0;
            rowCount++;
        }

        curr = minNode;
    }
    std::cout << std::endl;
}

void Grid::setValue(int xPos, int yPos, char value) {
    Node* curr = head;
    Node* prev;

    while(xPos != 0) {
        Node* minNode = NULL;
        if (curr->val == ' ') curr->val = '.';
        getGrid();
        for (auto itr = curr->neighbors.begin(); itr != curr->neighbors.end(); itr++) {
            if ((*itr) == prev) continue;
            minNode = Node::getMinNode(minNode, (*itr));
        };
        prev = curr;
        curr = minNode;
        xPos--;
    }

    while (yPos != 0) {
        Node* maxNode = NULL;
        if (curr->val == ' ') curr->val = '.';
        getGrid();
        for (auto itr = curr->neighbors.begin(); itr != curr->neighbors.end(); itr++) {
            maxNode = Node::getMaxNode(maxNode, (*itr));
        }

        curr = maxNode;
        yPos--;
    } 

    curr->val = value;
    if (value == '^') startNode = curr;

    getGrid(true);
}

void Grid::pathfind(int mode) {
    std::map<int, bool> visited;
    counter = 0;

    switch (mode) {
        case 0:
            DFS(startNode, visited);
            break;
        case 1:
            BFS(startNode, visited);
            break;
    }

    std::cout << "Path Length: " << counter << std::endl;
    getGrid(true);
}

Node* Grid::DFS(Node* node, std::map<int, bool> visited) {
    counter++;
    if (node->val == '*') return node;  
    if (node->val == ' ') node->val = '.';
    visited[node->position] = true;

    getGrid();

    for (auto itr = node->neighbors.begin(); itr != node->neighbors.end(); itr++) {
        if (!visited[(*itr)->position] && (*itr)->val != '|') {
            Node* ret = DFS((*itr), visited);
            if (ret != NULL) return ret;
        }
    }

    return NULL;
}

Node* Grid::BFS(Node* node, std::map<int, bool> visited) {
    std::list<Node*> queue;
    Node* ptr;

    visited[node->position] = true;
    queue.push_back(node);

    while(!queue.empty()) {
        counter++;
        ptr = queue.front();
        queue.pop_front();

        if (ptr->val == '*') return node;
        if (ptr->val == ' ') ptr->val = '.';

        getGrid();

        for (auto itr = ptr->neighbors.begin(); itr != ptr->neighbors.end(); itr++) {
            if (!visited[(*itr)->position] && (*itr)->val != '|') {
                visited[(*itr)->position] = true;
                queue.push_back((*itr));
            }
        }
    }

    return NULL;
}

Node* Grid::dijkstra(Node* node) {
    std::vector<int> dist(size);
    std::vector<bool> sptSet(size);

    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    return nullptr;
}
