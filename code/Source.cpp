#include "Auxiliary.h"
#include "Graph_algorithms.h"


Graph prep1Graph() {
    std::vector<std::string> vertices_names = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k" };
    Graph graph("graph1", vertices_names);
    graph.addBiEdge("a", "b", 2);
    graph.addBiEdge("a", "c", 3);
    graph.addBiEdge("b", "d", 1);
    graph.addBiEdge("b", "e", 2);
    graph.addBiEdge("c", "e", 3);
    graph.addBiEdge("c", "f", 1);
    graph.addBiEdge("d", "g", 2);
    graph.addBiEdge("e", "g", 2);
    graph.addBiEdge("f", "g", 4);
    graph.addBiEdge("f", "h", 3);
    graph.addBiEdge("g", "k", 6);
    graph.addBiEdge("g", "h", 2);
    graph.addBiEdge("h", "i", 1);
    graph.addBiEdge("h", "j", 1);
    graph.addBiEdge("i", "k", 2);
    graph.addBiEdge("j", "k", 3);
    return graph;
}

Graph prep2Graph() {
    std::vector<std::string> vertices_names = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n"};
    Graph graph("graph2", vertices_names);
    graph.addBiEdge("a", "c", 1);
    graph.addBiEdge("a", "d", 1);
    graph.addBiEdge("b", "e", 1);
    graph.addBiEdge("b", "f", 1);
    graph.addBiEdge("c", "g", 3);
    graph.addBiEdge("d", "h", 2);
    graph.addBiEdge("e", "g", 2);
    graph.addBiEdge("e", "h", 1);
    graph.addBiEdge("f", "h", 1);
    graph.addBiEdge("g", "k", 3);
    graph.addBiEdge("g", "i", 1);
    graph.addBiEdge("h", "i", 3);
    graph.addBiEdge("h", "j", 2);
    graph.addBiEdge("i", "l", 1);
    graph.addBiEdge("j", "l", 1);
    graph.addBiEdge("j", "m", 2);
    graph.addBiEdge("k", "n", 2);
    graph.addBiEdge("l", "n", 1);
    graph.addBiEdge("m", "n", 2);
    return graph;
}

int main() {
    Graph graph1 = prep1Graph();
    //Graph graph2 = prep2Graph();
    graph1.printGraph();
    //graph2.printGraph();
    std::vector<Node*> from_a_to_k = Dijkstra(graph1, "a", "k");
    std::vector<std::vector<double>> okey = Floyd_Warshall(graph1);
    Auxiliary::print_matrix(okey);
}