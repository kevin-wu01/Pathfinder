#include "Node.h"
#include <cstddef>
#include <iostream>

Node::Node() {
    val = ' ';
    neighbors = std::vector<Node*>();
}

Node::Node(int _position) {
    position = _position;
    val = ' ';
}

Node::Node(int _position, char _val) {
    val = _val;
    neighbors = std::vector<Node*>();
}

Node::Node(char _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
}

Node* Node::getMinNode(Node* n1, Node* n2) {
    if (n1 == NULL && n2 == NULL) return NULL;
    if (n1 == NULL) return n2;
    if (n2 == NULL) return n1;

    return n1->position > n2->position ? n2 : n1;
}

Node* Node::getMaxNode(Node* n1, Node* n2) {
    if (n1 == NULL && n2 == NULL) return NULL;
    if (n1 == NULL) return n2;
    if (n2 == NULL) return n1;

    return n1->position > n2->position ? n1 : n2;
}
