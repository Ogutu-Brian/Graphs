#include "Edge.h"
template <typename T>
Edge<T>::Edge(T* start_vertex,T* end_vertex,double edge_weight)
{
    this->start_vertex=start_vertex;
    this->end_vertex=end_vertex;
    this->edge_weight=edge_weight;
}
template <typename T>
Edge<T>::~Edge() {}
template <typename T>
T* Edge<T>::get_start_vertex()
{
    return this->start_vertex;
}
template <typename T>
T* Edge<T>::get_end_vertex()
{
    return this->end_vertex;
}
template <typename T>
T* Edge<T>::get_edge_weight()
{
    return this->edge_weight;
}
