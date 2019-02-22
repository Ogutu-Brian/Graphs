#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED
template<typename T>
class Edge
{
private:
    T* start_vertex;
    T* end_vertex;
    double edge_weight;
public:
    Edge(T* start_vertex, T* end_vertex, double edge_weight);
    ~Edge();
    T* get_start_vertex();
    T* get_end_vertex();
    T* get_edge_weight();
};
#endif // EDGE_H_INCLUDED
