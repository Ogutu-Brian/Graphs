#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include "Graph.h"
#include "Graph.cpp"
#include "KeyObject.h"
#include <CSC1310\src\String.cpp>
using namespace std;
int main()
{
    Graph<KeyObject> graph(4);
    string edges_file;
    string vertices_file;
    edges_file="romanian_mileages.txt";
    std::ifstream edges(edges_file);
    char* vertex = new char[5000];
    char* begin_vertex = new char[5000];
    char* end_vertex= new char[5000];
    double edge_weight;
    while(edges>>begin_vertex>>end_vertex>>edge_weight)
    {
        String* _begin_vertex=new String(begin_vertex);
        String* _end_vertex=new String(end_vertex);
        KeyObject* begin_object = new KeyObject(_begin_vertex);
        KeyObject* end_object = new KeyObject(_end_vertex);
        graph.addEdge(begin_object,end_object,edge_weight);
    }
    vertices_file="romanian_cities.txt";
    std::ifstream vertices(vertices_file);
    while(vertices>>vertex)
    {
        String* _vertex = new String(vertex);
        KeyObject* vertex_object = new KeyObject(_vertex);
        graph.addVertex(vertex_object);
    }
    std::cout<<"BFS:"<<std::endl;
    graph.print_traversed_vertices(graph.bfs());
    std::cout<<"\n"<<std::endl;
    std::cout<<"DFS:"<<std::endl;
    graph.print_traversed_vertices(graph.dfs());
}
