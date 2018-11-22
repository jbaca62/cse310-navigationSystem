#ifndef HEAP_H
#define HEAP_H
#include "Vertex.h"


class Heap
{
    public:
        Heap();
        Heap(int, int, Vertex*);
        void build_heap(Vertex*, int, int);
        static Heap initialize(int, Vertex*);
        void min_heapify(int);
        void print_heap();
        void decrease_key(int, int, int);
        void heap_insert(int, int);
        Vertex delete_min(int);
        Vertex* get_vertex(int);
        //bool add_element(Element, int);
        void set_H(Vertex*);
        int get_capacity();
        int get_size();
        Vertex* get_H();
        static int parent(int);
        static int left(int);
        static int right(int);


    protected:

    private:
        int capacity;
        int size;
        Vertex *H;
};

#endif // HEAP_H
