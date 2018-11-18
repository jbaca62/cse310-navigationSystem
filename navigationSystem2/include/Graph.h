#ifndef GRAPH_H
#define GRAPH_H
#include "Element.h"
#include "Edge.h"


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

    private:
        int n; //number of vertices, size of G
        int m; //number of edges
        Edge* vertices;

};

#endif // GRAPH_H
