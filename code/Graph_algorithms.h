#pragma once
#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include "Graph.h"

Node* argminNgbs(const std::map<Node*, double>&);
std::vector<Node*> Dijkstra(const Graph&, const std::string&, const std::string&);
std::vector<std::vector<double>> Floyd_Warshall(const Graph&);

#endif