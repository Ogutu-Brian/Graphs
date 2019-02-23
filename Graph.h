#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <vector>
#include "CSC1310\include\ListLinked.h"
#include "KeyObject.h"
#include "Edge.h"
#include "Edge.cpp"
#include <iostream>
using namespace std;
using std::vector;
using CSC1310::ListLinked;
template <typename T>
class Graph
{
private:
    int max_number_vertices;
    int vertex_index=0;
    vector<T*> vertices;
    vector<Edge<T>> edges;
public:
    Graph(int max_num_vertices);
    virtual ~Graph();
    void addVertex(T* item);
    void addEdge(T* start_vertex_key,T* end_vertex_key,double edge_weight);
    ListLinked<T>* dfs();
    ListLinked<T>* bfs();
    //checks is there is an edge between the vertices
    bool edge_exists(T* start_vertex,T* end_vertex);
    //prints the traversed vertices
    void print_traversed_vertices(ListLinked<T>* traversedList);
    //Gets the vertex index
    int getVertexIndex(T* vertexValue);
    //traverses the elements of the adjacency matrix as it appends adds values to list
    int traverseAdjacencyMatrix(int**& matrix,int root,ListLinked<T>*& _list,vector<int>& visitedVertices,int& counter);
    //Traverses the elements in adjacency list
    int traverseAdjacencyList(vector<vector<T*>>& adjacencyLists,ListLinked<T>*& _list,vector<T*>& visitedNodes,vector<T*>& nodeStack);
};
#endif // GRAPH_H_INCLUDED

