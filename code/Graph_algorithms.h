#pragma once
#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include "Graph.h"

Graph* generateRandomGraph(const std::string&, int, double, bool);
Graph* generateRandomLocatedGraph(const std::string&, int, double, double, double, bool);
//Graph* generateRandomGraph(std::string, const std::string*, double, bool);
Node* argminNgbs(const std::map<Node*, double>&);
std::vector<Node*> Dijkstra(const Graph&, const std::string&, const std::string&);
std::vector<std::vector<double>> Floyd_Warshall(const Graph&);

#endif