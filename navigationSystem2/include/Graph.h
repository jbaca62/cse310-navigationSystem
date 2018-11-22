#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include "Vertex.h"
#include "Heap.h"
#include <iostream>

using namespace std;

class Graph
{

    public:
        Graph();
        Graph(int, int);
        void build_graph(int, int, Edge*);
        static Graph initialize(int, int);
        void print_graph();
        int get_n();
        Element * get_G();
        string shortest_path(int, int, int);
        Vertex* initialize_single_source(int);

    private:
        int n; //number of vertices, size of G
        int m; //number of edges
        Edge **edges;
        Vertex *vertices;

};

#endif // GRAPH_H
