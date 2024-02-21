#include "Graph_algorithms.h"

const double INFTY = std::numeric_limits<double>::max();

Node* argminNgbs(const std::map<Node*, double>& vertex_map) {
    double min = std::numeric_limits<double>::max();
    Node* argmin = nullptr;
    for (const auto myPair : vertex_map) {
        if (myPair.second < min) {
            min = myPair.second;
            argmin = myPair.first;
        }
    }
    return argmin;
}

std::vector<Node*> Dijkstra(const Graph& graph, const std::string& starting_vertex_name, const std::string& ending_vertex_name) {
    Node* starting_vertex = graph.findVertexByName(starting_vertex_name);
    // init
    std::map<Node*, double> distances = {};
    std::map<Node*, Node*> predecesors = {};
    for (Node* vertex : graph.getVertices()) {
        distances[vertex] = INFTY;
        predecesors[vertex] = nullptr;
    }
    distances[starting_vertex] = 0;
    // main loop
    while (!distances.empty()) {
        Node* chosen_vertex = argminNgbs(distances);
        // relaxing
        for (Node* neighbour : chosen_vertex->getNbhdList()) {
            if (distances.find(neighbour) == distances.end()) {
                continue;
            }
            double new_distance = distances[chosen_vertex] + chosen_vertex->getNeighbours().at(neighbour);
            if (distances[neighbour] > new_distance) {
                distances[neighbour] = new_distance;
                predecesors[neighbour] = chosen_vertex;
            }
        }
        distances.erase(chosen_vertex);
    }
    std::vector<Node*> quickest_path = { graph.findVertexByName(ending_vertex_name) };
    while (predecesors[quickest_path.back()]) {
        quickest_path.push_back(predecesors[quickest_path.back()]);
    }
    std::reverse(quickest_path.begin(), quickest_path.end());
    return quickest_path;
}

std::vector<std::vector<double>> Floyd_Warshall(const Graph& graph) {
    std::vector<std::vector<double>> distance_matrix = graph.getAdjacencyMatrix();
    int matrix_size = distance_matrix[0].size(); // conversion from 'size_t' to 'int', possible loss of data
    for (int k = 0; k < matrix_size; ++k) {
        for (int i = 0; i < matrix_size; ++i) {
            double partial_distance = distance_matrix[i][k];
            for (int j = 0; j < matrix_size; ++j) {
                distance_matrix[i][j] = std::min(distance_matrix[i][j], partial_distance + distance_matrix[k][j]);
            }
        }
    }
    return distance_matrix;
}