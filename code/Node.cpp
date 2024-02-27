#include "Node.h"
#include <iostream>

Node::Node(const std::string& nodeName) {
    name = nodeName;
}

Node::~Node() {}

std::string Node::getName() const { return name; }

const std::map<Node*, double>& Node::getNeighbours() const { return neighbours; }

bool Node::ifNeighbourExists(Node& neighbour) const {
    if (neighbours.count(&neighbour) > 0) {
        return 1;
    }
    return 0;
}

bool Node::ifNeighbourExists(const std::string& neighbour) const {
    for (const auto myPair : neighbours) {
        if (myPair.first->getName() == neighbour) {
            return 1;
        }
    }
    return 0;
}

void Node::addNeighbour(Node& neighbour) {
    if (!ifNeighbourExists(neighbour)) {
        neighbours[&neighbour] = 1;
    }
}

void Node::addNeighbour(Node& neighbour, double weight) {
    if (!ifNeighbourExists(neighbour)) {
        neighbours[&neighbour] = weight;
    }
}

void Node::removeNeighbour(Node& neighbour) {
    auto it = neighbours.find(&neighbour);
    if (it != neighbours.end()) {
        neighbours.erase(it);
    }
}

void Node::changeNeighbWeight(Node& neighbour, double weight) {
    auto iterator = neighbours.find(&neighbour);
    if (iterator != neighbours.end()) {
        iterator->second = weight;
    }
}

void Node::printNode() const {
    std::cout << name << ": ";
    if (!neighbours.empty()) {
        auto iterator = neighbours.begin();
        while (iterator != neighbours.end()) {
            std::cout << "(" << iterator->first->getName() << ", " << iterator->second << ")";
            if (++iterator != neighbours.end()) {
                std::cout << ", ";
            }
            else {
                std::cout << ".";
            }
        }
    }
    std::cout << "\n";
}

std::vector<Node*> Node::getNbhdList() const {
    std::vector<Node*> neighbours;

    for (const auto& pair : this->neighbours) {
        neighbours.push_back(pair.first);
    }

    return neighbours;
}

bool Node::operator==(const Node& other) const {
    return this->name == other.name;
}

LocatedNode::LocatedNode(const std::string& name) : Node(name) { x_coordinate = 0; y_coordinate = 0; }

LocatedNode::LocatedNode(const std::string& name, double x, double y) : Node(name), x_coordinate(x), y_coordinate(y) {}

LocatedNode::~LocatedNode() {}

double LocatedNode::getx() { return x_coordinate; }

double LocatedNode::gety() { return y_coordinate; }