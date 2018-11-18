#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(){

}

Graph::Graph(int n, int m)
{
    this->n = n;
    this->m = m;
    this->vertices = new Edge[n];
}


Graph Graph::initialize(int n, int m){
    Graph graph = Graph(n, m);
    return graph;
}

void Graph::build_graph(int n, int m, Edge* v){
        vertices = v;
}

void Graph::print_graph(){
    cout << "Vertice Size: " << this->n << " Edge Size: " << this->m << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        Edge e = vertices[i];
        while(e.get_next() != 0){
            cout << "(" << e.get_index() << "," << e.get_weight() << "); ";
            e = *e.get_next();
        }
        cout <<"(" << e.get_index() << "," <<e.get_weight() << ")" <<  endl;
    }
}

int Graph::get_n(){
    return this->n;
}

