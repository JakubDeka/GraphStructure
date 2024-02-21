#include "Graph.h"
#include "Node.h"
#include <iostream>
#include "Auxiliary.h"
#include <algorithm>

const double INFTY = std::numeric_limits<double>::max();

Graph::Graph(std::string graph_name) : name(graph_name) { numVertices = 0; }

Graph::Graph(std::string graph_name, std::vector<std::string> vertices_names) : name(graph_name) {
    numVertices = 0;
    for (std::string vertex_name : vertices_names) {
        Node* new_node = new Node(vertex_name);
        vertices.push_back(new_node);
    }
}

Graph::~Graph() {}

std::string Graph::getName() const { return name; }

std::vector<Node*> Graph::getVertices() const { return vertices; }

std::vector<std::string> Graph::getVerticesNames() const {
    std::vector<std::string> names_list;
    for (Node* vertex : vertices) {
        names_list.push_back(vertex->getName());
    }
    return names_list;
}

std::vector<std::vector<double>> Graph::getAdjacencyMatrix() const {
    std::vector<std::vector<double>> adjMatrix;
    for (Node* vertex : vertices) {
        std::vector<double> row;
        std::string name = vertex->getName(); 
        std::map<Node*, double> ngbh_list = vertex->getNeighbours();
        for (Node* another_vertex : vertices) {
            std::string another_name = another_vertex->getName();
            if (name == another_name) { row.push_back(0); }
            else if (ngbh_list.find(another_vertex) == ngbh_list.end()) { row.push_back(INFTY); }
            else { row.push_back(ngbh_list[another_vertex]); }
        }
        adjMatrix.push_back(row);
    }
    return adjMatrix;
}

bool Graph::ifVertexPresent(const Node* vertex) const {
    if (std::find(vertices.begin(), vertices.end(), vertex) != vertices.end()) {
        return true;
    }
    return false;
}

Node* Graph::ifVertexPresent(const std::string vertex_name) const {
    for (Node* vertex : vertices) {
        if (vertex->getName() == vertex_name) {
            return vertex;
        }
    }
    return nullptr;
}

void Graph::addVertex(Node& vertex) {
    if (!ifVertexPresent(&vertex)) {
        vertices.push_back(&vertex);
    }
}

Node* Graph::addVertex(const std::string& vertex_name) {
    if (!ifVertexPresent(vertex_name)) {
        Node* vertex = new Node(vertex_name);
        vertices.push_back(vertex);
        return vertex;
    }
    return nullptr;
}

bool Graph::ifVerticesPresent(std::string start_vertex, std::string destination_vertex) const {
    if (ifVertexPresent(start_vertex) && ifVertexPresent(destination_vertex)) {
        return true;
    }
    return false;
}

Node* Graph::findVertexByName(const std::string& vertex_name) const {
    for (Node* vertex : vertices) {
        if (vertex->getName() == vertex_name) {
            return vertex;
        }
    }
    return nullptr;
}

// we assume that the vertices exist in the graph
bool Graph::ifEdgeExists(const std::string& start_vertex, const std::string& destination_vertex) const {
    Node* first_vertex = findVertexByName(start_vertex);
    if (!first_vertex->ifNeighbourExists(destination_vertex)) {
        return false;
    }
    return true;
}

// we assume that the vertices exist in the graph
bool Graph::ifEdgeExists(const Node* start_vertex, Node* destination_vertex) {
    if (!start_vertex->ifNeighbourExists(*destination_vertex)) {
        return false;
    }
    return true;
}

void Graph::addEdge(const std::string& start_vertex, const std::string& destination_vertex) {
    if (ifVerticesPresent(start_vertex, destination_vertex) && !ifEdgeExists(start_vertex, destination_vertex)) {
        Node* first_vertex = findVertexByName(start_vertex);
        Node* second_vertex = findVertexByName(destination_vertex);
        first_vertex->addNeighbour(*second_vertex);
    }
}

void Graph::addEdge(const std::string& start_vertex, const std::string& destination_vertex, double weight) {
    if (ifVerticesPresent(start_vertex, destination_vertex) && !ifEdgeExists(start_vertex, destination_vertex)) {
        Node* first_vertex = findVertexByName(start_vertex);
        Node* second_vertex = findVertexByName(destination_vertex);
        first_vertex->addNeighbour(*second_vertex, weight);
    }
}

void Graph::addBiEdge(const std::string& start_vertex, const std::string& destination_vertex) {
    if (ifVerticesPresent(start_vertex, destination_vertex) && !ifEdgeExists(start_vertex, destination_vertex) && !ifEdgeExists(destination_vertex, start_vertex)) {
        Node* first_vertex = findVertexByName(start_vertex);
        Node* second_vertex = findVertexByName(destination_vertex);
        first_vertex->addNeighbour(*second_vertex);
        second_vertex->addNeighbour(*first_vertex);
    }
}

void Graph::addBiEdge(const std::string& start_vertex, const std::string& destination_vertex, double weight) {
    if (ifVerticesPresent(start_vertex, destination_vertex) && !ifEdgeExists(start_vertex, destination_vertex) && !ifEdgeExists(destination_vertex, start_vertex)) {
        Node* first_vertex = findVertexByName(start_vertex);
        Node* second_vertex = findVertexByName(destination_vertex);
        first_vertex->addNeighbour(*second_vertex, weight);
        second_vertex->addNeighbour(*first_vertex, weight);
    }
}

void Graph::removeEdge(const std::string& start_vertex, const std::string& destination_vertex) {
    if (ifEdgeExists(start_vertex, destination_vertex)) {
        Node* first_vertex = findVertexByName(start_vertex);
        Node* second_vertex = findVertexByName(destination_vertex);
        first_vertex->removeNeighbour(*second_vertex);
    }
    return;
}

void Graph::removeEdge(Node* start_vertex, Node* destination_vertex) {
    if (ifEdgeExists(start_vertex, destination_vertex)) {
        start_vertex->removeNeighbour(*destination_vertex);
    }
    return;
}

void Graph::removeVertex(const std::string& vertex_name) {
    if (!ifVertexPresent(vertex_name)) {
        return;
    }
    Node* main_vertex = findVertexByName(vertex_name);
    for (Node* vertex : vertices) {
        removeEdge(vertex, main_vertex);
        removeEdge(main_vertex, vertex);
    }
    vertices.erase(std::remove(vertices.begin(), vertices.end(), main_vertex), vertices.end());
}

void Graph::removeVertex(Node& main_vertex) {
    Node* vertex_address = &main_vertex;
    if (!ifVertexPresent(vertex_address)) {
        return;
    }
    for (Node* vertex : vertices) {
        removeEdge(vertex, vertex_address);
        removeEdge(vertex_address, vertex);
    }
    vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex_address), vertices.end());
}

void Graph::printGraph() const {
    std::cout << "Graph name: " << name << "\n";
    for (Node* vertex : vertices) {
        vertex->printNode();
    }
}

void Graph::printAdjacencyMatrix() const {
    std::vector< std::vector<double>> matrix = getAdjacencyMatrix();
    Auxiliary::print_matrix(matrix);
}