#include "Node.h"

Node::Node() {
    val = ' ';
    neighbors = std::vector<Node*>();
}

Node::Node(char _val) {
    val = _val;
    neighbors = std::vector<Node*>();
}

Node::Node(char _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
}