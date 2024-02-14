#include <iostream>
#include <string>
#include "Node.h"
#include "Graph.h"
//#include "test_node.cpp"

void greet() {
    std::cout << "Hello World\n";
    std::string test = "";
    while (test != "hello" && test != "hi" && test != "hey") {
        std::cin >> test;
    }
    std::cout << "Goodbye World\n";
}

int main() {

    std::cout << "------ Testing nodes ------\n";
    
    Node myNode("hej");
    Node anotherNode = Node("siema");
    Node anotherNode1 = Node("hi");
    Node anotherNode2 = Node("oj");
    Node anotherNode3 = Node("aaaaa");

    std::vector<std::string> vertices_names = { "a", "c"};
    Graph graph("sote", vertices_names);
    graph.addVertex("fu");
    graph.addVertex(anotherNode);
    graph.addEdge("a", "fu");
    graph.addEdge("a", "c", 0);
    graph.addEdge("c", "a", 0);
    graph.addEdge("fu", "siema", 2.1);
    graph.printGraph();
    graph.removeEdge("fu", "siema");
    graph.removeEdge("fu", "a");
    graph.printGraph();
    graph.addEdge("a", "bet");
    graph.addEdge("a", "fu", 21);
    graph.addEdge("fu", "siema", 21);
    graph.addEdge("a", "siema");
    graph.addVertex(anotherNode2);
    graph.addEdge(anotherNode2.getName(), "a", -9.85);
    graph.addEdge(anotherNode2.getName(), "fu", -0.02);
    graph.printGraph();
    graph.removeVertex("fu");
    graph.removeVertex(anotherNode2);
    graph.printGraph();
}