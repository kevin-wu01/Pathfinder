#include <vector>

class Node {
public:
    char val;
    std::vector<Node*> neighbors;

    Node();
    Node(char _val);
    Node(char _val, std::vector<Node*> _neighbors);
};