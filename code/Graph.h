#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <list>
#include "Node.h"

class Graph
{
public:
    Graph(std::string name);
    Graph(std::string name, std::vector<std::string> vertices_names);
    ~Graph();
    std::string getName() const;
    std::vector<Node*> getVertices() const;
    std::vector<std::string> getVerticesNames() const;
    void addVertex(const std::string&);
    void addVertex(Node&);
    Node* findVertexByName(const std::string&) const;
    void addEdge(std::string, std::string);
    void addEdge(std::string, std::string, double);
    void removeEdge(std::string, std::string);
    void removeEdge(Node*, Node*);
    void removeVertex(const std::string&);
    void removeVertex(Node&);
    void printGraph() const;
private:
    std::string name;
    std::vector<Node*> vertices;
    int numVertices;
    bool ifVertexPresent(const std::string) const;
    bool ifVertexPresent(const Node*) const ;
    bool ifVerticesPresent(const std::string, const std::string) const;
    bool ifEdgeExists(const std::string&, const std::string&) const;
    bool ifEdgeExists(const Node*, Node*);
};

#endif