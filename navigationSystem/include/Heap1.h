#ifndef HEAP_H
#define HEAP_H

#include "Element.h"


class Heap
{
    public:
        Heap();
        Heap(int, int, Element*);
        void build_heap(Element*, int, int);
        static Heap initialize(int n);
        void max_heapify(int);
        void print_heap();
        void increase_key(int, int, int);
        void heap_insert(int, int);
        Element delete_max(int);
        bool add_element(Element, int);
        void set_H(Element*);
        int get_capacity();
        static int parent(int);
        static int left(int);
        static int right(int);


    protected:

    private:
        int capacity;
        int size;
        Element *H;
};

#endif // HEAP_H
