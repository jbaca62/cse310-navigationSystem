#include <iostream>
#include "Graph.h"
#include "Heap.h"
#include "Vertex.h"

using namespace std;

Graph::Graph(){

}

Graph::Graph(int n, int m)
{
    this->n = n;
    this->m = m;
    this->edges = new Edge*[n + 1];
}


Graph Graph::initialize(int n, int m){
    Graph graph = Graph(n, m);
    return graph;
}

void Graph::build_graph(int n, int m, Edge* v){
        for(int i = 1; i <= v->get_index(); i++){   //size of array stored in v[0]
            //creating graph in this way requires that Edges already have memory allocated
            edges[i] = &v[i];
        }
}

void Graph::print_graph(){
    cout << "Vertice Size: " << this->n << " Edge Size: " << this->m << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        if(edges[i] != 0){
            Edge e = *edges[i];
            while(e.get_next() != 0){
                cout << "(" << e.get_index() << "," << e.get_weight() << "); ";
                e = *e.get_next();
            }
            cout <<"(" << e.get_index() << "," << e.get_weight() << ")" <<  endl;
        }
        else{
            cout << endl;
        }
    }
}

//implementation of dijkstra's shortest path algorithm
string Graph::shortest_path(int start, int finish, int flag){
    Heap min_heap = Heap();

    //psuedo code
    //initialize single source
    //S = empty set
    //Q = G.V
    //while Q is not empty set
    //  u = Extract-min(Q)
    //  S = S union {u}
    //  for each vertex v in G.Adj[u]
    //      Relax(u,v,w)



    return "Shortest Path Return";
}


void initialize_single_source(int start){
    //Vertex* v = new Vertex[n+1];
    //create Vertex for each vertex in Graph
    //for(int i = 1; i <= n; i++){
    //    v[i] = Vertex();
    //}
    //v[start].distance = 0;
    //psuedo code
    //for each vertex v in G.V
    //  v.d = inf
    //  v.prev = NIL
    //s.d = 0

}

void relax(){
    //psuedo cod
    //if v.d > u.d + w(u, v)
    //  v.d = u.d + w(w, v)
    //  v.prev = u
}

int Graph::get_n(){
    return this->n;
}

