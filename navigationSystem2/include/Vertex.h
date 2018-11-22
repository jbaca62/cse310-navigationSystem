#ifndef VERTEX_H
#define VERTEX_H
#include "Edge.h"


class Vertex
{
    public:
        Vertex();
        Vertex(int);
        void relax(Vertex*, int);
        static bool contains(Vertex*, int, int);
        Edge* get_edges();
        int get_distance();
        int get_index();
        Vertex* get_previous();
        void set_index(int);
        void set_edges(Edge*);
        void set_distance(int);
        void set_previous(Vertex*);
        static void print_vertices(Vertex*, int);


    private:
        int index;
        int distance;
        Vertex* previous;
        Edge* edges;
};

#endif // VERTEX_H
