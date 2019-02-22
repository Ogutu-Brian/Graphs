#include "Graph.h"
using CSC1310::ListLinked;
template <typename T>
Graph<T>::Graph(int max_num_vertices)
{
    max_number_vertices = max_num_vertices;
}
template <typename T>
Graph<T>::~Graph() {}
template <typename T>
void Graph<T>::addVertex(T* item)
{
    vertices.push_back(item);
}
template<typename T>
void Graph<T>::addEdge(T* start_vertex_key,T* end_vertex_key,double edge_weight)
{
    Edge<T> edge(start_vertex_key,end_vertex_key,edge_weight);
    edges.push_back(edge);
}
template <typename T>
bool Graph<T>::edge_exists(T* start_vertex, T* end_vertex)
{
    for(Edge<T> edge:edges)
    {
        if(edge.get_start_vertex()->getKey()->get_std_str()==start_vertex->getKey()->get_std_str() && edge.get_end_vertex()->getKey()->get_std_str()==end_vertex->getKey()->get_std_str())
        {
            return true;
        }
    }
    return false;
}
template <typename T>
int Graph<T>::getVertexIndex(T* vertexValue)
{
    for(int i=0; i < vertices.size(); i++)
    {
        if(vertices[i]->getKey()->get_std_str()==vertexValue->getKey()->get_std_str())
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
int Graph<T>::traverseAdjacencyMatrix(int**& matrix,int root,ListLinked<T>*& _list,vector<int>& visitedVertices,int&counter)
{
    if(counter == vertices.size())
    {
        return 0;
    }
    else
    {
        vector<int> neighbors;
        bool is_leaf = true;
        bool visited = false;
        for(int value: visitedVertices)
        {
            if(value == root)
            {
                visited = true;
                break;
            }
        }
        if(!visited)
        {
            counter +=1;
            _list->add(vertices[root]);
            visitedVertices.push_back(root);
            for(int i = 0; i < vertices.size(); i++)
            {
                if(matrix[root][i]==1)
                {
                    neighbors.push_back(i);
                    is_leaf = false;
                }
            }
            if(!is_leaf)
            {
                for(int j = 0; j < neighbors.size(); j++)
                {
                    traverseAdjacencyMatrix(matrix,neighbors[j],_list,visitedVertices,counter);
                }
            }
        }
    }
}
template <typename T>
int Graph<T>::traverseAdjacencyList(vector<vector<T*>>& adjacencyLists,ListLinked<T>*& _list,vector<T*>& visitedNodes,vector<T*>& nodeStack)
{
    if(adjacencyLists.empty())
    {
        return -1;
    }
    while(visitedNodes.size()<vertices.size())
    {
        if(visitedNodes.empty())
        {
            nodeStack.push_back(adjacencyLists[0][0]);
            _list->add(adjacencyLists[0][0]);
        }
        for(vector<T*> adjacencyList: adjacencyLists)
        {
            if(nodeStack[0]->getKey()->get_std_str() == adjacencyList[0]->getKey()->get_std_str())
            {
                if(adjacencyList.size()>1)
                {
                    for(int i=1; i < adjacencyList.size(); i++)
                    {
                        bool visited = false;
                        bool in_stack = false;
                        for(T* visitedNode: visitedNodes)
                        {

                            if(adjacencyList[i]->getKey()->get_std_str() == visitedNode->getKey()->get_std_str())
                            {
                                visited = true;
                                break;
                            }
                        }
                        for(T* stackNode: nodeStack)
                        {
                            if(adjacencyList[i]->getKey()->get_std_str()==stackNode->getKey()->get_std_str())
                            {
                                in_stack=true;
                                break;
                            }
                        }
                        if(!visited && !in_stack)
                        {
                            _list->add(adjacencyList[i]);
                            nodeStack.push_back(adjacencyList[i]);
                        }
                    }
                }
                break;
            }
        }
        visitedNodes.push_back(nodeStack[0]);
        if(nodeStack.size()>=1)
        {
            nodeStack.erase(nodeStack.begin());
        }
        if(nodeStack.empty())
        {
            for(T* vertex: vertices)
            {
                bool unvisited = true;
                for(T* visitedNode: visitedNodes)
                {
                    if(vertex->getKey()->get_std_str()==visitedNode->getKey()->get_std_str())
                    {
                        unvisited=false;
                        break;
                    }
                }
                if(unvisited)
                {
                    nodeStack.push_back(vertex);
                    _list->add(vertex);
                    break;
                }
            }
        }
    }
}
template <typename T>
ListLinked<T>* Graph<T>::bfs()
{
    vector<vector<T*>> adjacencyLists;
    vector<T*> visitedNodes;
    vector<T*> nodeStack;
    ListLinked<T>* traversedList=new ListLinked<T>();
    if(vertices.empty())
    {
        return NULL;
    }
    for(int i =0; i < vertices.size(); i++)
    {
        vector<T*> vectorList;
        vectorList.push_back(vertices[i]);
        for(int j =0; j < vertices.size(); j++)
        {
            if(edge_exists(vertices[i],vertices[j]))
            {
                vectorList.push_back(vertices[j]);
            }
        }
        adjacencyLists.push_back(vectorList);
    }
    traverseAdjacencyList(adjacencyLists,traversedList,visitedNodes,nodeStack);
    return traversedList;
}
template <typename T>
ListLinked<T>* Graph<T>::dfs()
{
    int** adjacencymatrix= new int*[vertices.size()];
    ListLinked<T>* traversedList = new ListLinked<T>();
    if(vertices.empty())
    {
        return NULL;
    }
    for(int i =0; i < vertices.size(); i++)
    {
        adjacencymatrix[i] = new int[vertices.size()];
    }
    for(int i =0; i < vertices.size(); i++)
    {
        for(int k=0; k < vertices.size(); k++)
        {
            if(edge_exists(vertices[i],vertices[k]))
            {
                adjacencymatrix[i][k]=1;
            }
            else
            {
                adjacencymatrix[i][k]=0;
            }
        }
    }
    int root = 0;
    int counter = 0;
    vector<int> visitedVertices;
    traverseAdjacencyMatrix(adjacencymatrix,root,traversedList,visitedVertices,counter);
    while(visitedVertices.size()!=vertices.size())
    {
        for(int i=0; i < vertices.size(); i++)
        {
            bool exists = false;
            for(int item: visitedVertices)
            {
                if(item == i)
                {
                    exists = false;
                    break;
                }
            }
            if(!exists)
            {
                traverseAdjacencyMatrix(adjacencymatrix,i,traversedList,visitedVertices,counter);
            }
        }
    }
    for(int i =0; i < vertices.size(); i++)
    {
        delete[] adjacencymatrix[i];
    }
    delete[] adjacencymatrix;
    return traversedList;
}
template <typename T>
void Graph<T>::print_traversed_vertices(ListLinked<T>* traversedList)
{
    for(int i =1; i <= traversedList->size(); i++)
    {
        std::cout<<traversedList->get(i)->getKey()->get_std_str()<<std::endl;
    }
}
