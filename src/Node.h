#include <vector>

class Node {
public:
    char val;
    int position;
    std::vector<Node*> neighbors;

    Node();
    Node(int _position);
    Node(int _position, char _val);
    Node(char _val, std::vector<Node*> _neighbors);

    static Node* getMinNode(Node* n1, Node* n2);
    static Node* getMaxNode(Node* n1, Node* n2);
};