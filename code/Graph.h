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
    std::vector<std::vector<double>> getAdjacencyMatrix() const;
    Node* addVertex(const std::string&);
    void addVertex(Node&);
    Node* findVertexByName(const std::string&) const;
    void addEdge(const std::string&, const std::string&);
    void addEdge(const std::string&, const std::string&, double);
    void addBiEdge(const std::string&, const std::string&);
    void addBiEdge(const std::string&, const std::string&, double);
    //void addBiEdge();
    void removeEdge(const std::string&, const std::string&);
    void removeEdge(Node*, Node*);
    void removeVertex(const std::string&);
    void removeVertex(Node&);
    void printGraph() const;
    void printAdjacencyMatrix() const;
    //std::vector<Node*> Dijkstra(const std::string&, const std::string&) const;
    //std::vector<std::vector<double>> Floyd_Warshall() const;
private:
    std::string name;
    std::vector<Node*> vertices;
    int numVertices;
    Node* ifVertexPresent(const std::string) const;
    bool ifVertexPresent(const Node*) const ;
    bool ifVerticesPresent(const std::string, const std::string) const;
    bool ifEdgeExists(const std::string&, const std::string&) const;
    bool ifEdgeExists(const Node*, Node*);
    //static Node* argminNgbs(const std::map<Node*, double>& vertex_map);
};

#endif