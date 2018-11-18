#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        Edge();
        Edge(int, int);
        void add_edge(int, int);
        int get_index();
        int get_weight();
        Edge* get_next();
        void set_index(int);
        void set_weight(int);


    private:
        int index;
        int weight;
        Edge* next;
};

#endif // EDGE_H
