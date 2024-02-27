#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
#include <unordered_map>
#include <map>

class Node
{
public:
    Node(const std::string&);
    ~Node();
    std::string getName() const;
    const std::map<Node*, double>& getNeighbours() const;
    bool ifNeighbourExists(Node& neighbour) const;
    bool ifNeighbourExists(const std::string& neighbour) const;
    void addNeighbour(Node& neighbour);
    void addNeighbour(Node& neighbour, double);
    void removeNeighbour(Node& neighbour);
    void changeNeighbWeight(Node& neighbour, double weight);
    void printNode() const;
    std::vector<Node*> getNbhdList() const;
    bool operator==(const Node& other) const;
protected:
    std::string name;
    std::map<Node*, double> neighbours;
};

class LocatedNode : public Node {
public:
    LocatedNode(const std::string&);
    LocatedNode(const std::string&, double x, double y);
    ~LocatedNode();
    double getx();
    double gety();
private:
    double x_coordinate;
    double y_coordinate;
};

#endif