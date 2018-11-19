#ifndef GRAPH_H
#define GRAPH_H
#include "Element.h"
#include "Edge.h"
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

    private:
        int n; //number of vertices, size of G
        int m; //number of edges
        // may implement vertices as array of pointers
        Edge *vertices;

};

#endif // GRAPH_H
