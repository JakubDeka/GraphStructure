#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Auxiliary.h"
#include <algorithm>

class Graph
{
public:
    Graph(std::string);
    Graph(std::string, std::vector<std::string>);
    ~Graph();
    std::string getName() const;
    std::vector<Node*> getVertices() const;
    std::vector<std::string> getVerticesNames() const;
    std::vector<std::vector<double>> getAdjacencyMatrix() const;
    virtual Node* addVertex(const std::string&);
    virtual void addVertex(Node&);
    Node* findVertexByName(const std::string&) const;
    void addEdge(const std::string&, const std::string&);
    void addEdge(const std::string&, const std::string&, double);
    void addBiEdge(const std::string&, const std::string&);
    void addBiEdge(const std::string&, const std::string&, double);
    //void addBiEdge();
    bool ifEdgeExists(const std::string&, const std::string&) const;
    bool ifEdgeExists(const Node*, Node*);
    void removeEdge(const std::string&, const std::string&);
    void removeEdge(Node*, Node*);
    void removeVertex(const std::string&);
    void removeVertex(Node&);
    void printGraph() const;
    void printAdjacencyMatrix() const;
protected:
    std::string name;
    std::vector<Node*> vertices;
    int numVertices;
    Node* ifVertexPresent(const std::string) const;
    bool ifVertexPresent(const Node*) const ;
    bool ifVerticesPresent(const std::string, const std::string) const;
    //static Node* argminNgbs(const std::map<Node*, double>& vertex_map);
};

class LocatedGraph : public Graph {
public:
    LocatedGraph(std::string);
    ~LocatedGraph();
    Node* addVertex(const std::string&, double vertex_x, double vertex_y);
    void addVertex(LocatedNode&);
};

#endif