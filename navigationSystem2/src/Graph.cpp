#include <iostream>
#include "Graph.h"


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
    Graph graph = Graph();
    graph.n = n;
    graph.m = m;
    graph.edges = new Edge*[n+1];
    graph.vertices = new Vertex[n+1];
    return graph;
}

void Graph::build_graph(int n, int m, Edge* e){
        for(int i = 1; i <= n; i++){   //size of array stored in v[0]
            if(e[i].get_index() != 0){
                edges[i] = &(e[i]); //creating graph in this way requires that Edges already have memory allocated
                vertices[i].set_edges(edges[i]);
            }
            else{
                edges[i] = 0;
            }
        }
}

void Graph::print_graph(){
    cout << this->n << " " << this->m << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        if(edges[i] != 0 ){
            Edge e = *edges[i];
            while(e.get_next() != 0){
                cout << "(" << e.get_index() << ", " << e.get_weight() << "); ";
                e = *e.get_next();
            }
            cout <<"(" << e.get_index() << ", " << e.get_weight() << ")" <<  endl;
        }
        else{
            cout << endl;
        }
    }
}

//implementation of dijkstra's shortest path algorithm
string Graph::shortest_path(int start, int finish, int flag){
    if((flag != 0 && flag != 1) && (start > n || finish > n)){
        return "Error: One or more of nodes is invalid.\nError: Invalid flag value.";
    }
    if((flag != 0 && flag != 1)){
        return "Error: Invalid flag value.";
    }
    if(start > n || finish > n){
        return "Error: One or more of nodes is invalid.";
    }

    string str = "";
    Vertex* V = initialize_single_source(start);
    //cout << V[1].get_index() << endl;
    Vertex* S = new Vertex[n + 1]; //not positive this is how it should be implemented
    Heap Q = Heap::initialize(n, V);
    Q.build_heap(V, n, 0);
    int s_size = 0;
    bool found = false;
    while(Q.get_size() != 0 && !found){
        //Q.print_heap();
        Vertex u = Q.delete_min(0);
        //cout << "Index of deleted: " << u.get_index() << endl;
        s_size++;
        S[s_size] = u;
        Vertex* U = &S[s_size];
        //Vertex::print_vertices(S, s_size);
        if(u.get_index() != finish){
            if(u.get_edges() != 0){
                Edge e = *u.get_edges();
                //cout << u.get_index() << " to adj " << e.get_index() << endl;
                while(e.get_next() != 0){
                    if(!Vertex::contains(S,s_size, e.get_index())){
                        int weight = e.get_weight();
                        //cout << "Edge index: " << e.get_index() << " Weight: " << e.get_weight() << endl;
                        Vertex* v1 = Q.get_vertex(e.get_index());
                        U->relax(v1, weight);
                    }
                    e = *e.get_next();
                    //cout << u.get_index() << " to adj " << e.get_index() << endl;
                }
                if(!Vertex::contains(S,s_size, e.get_index())){
                    int weight = e.get_weight();
                    //cout << "Edge index: " << e.get_index() << " Weight: " << weight << endl;
                    Vertex* v2 = Q.get_vertex(e.get_index());
                    U->relax(v2, weight);
                }
                Q.min_heapify(1);
                //Q.print_heap();
            }
        }
        else{
            found = true;
        }
    }
    if(S[s_size].get_distance() == 2147483647){
        str = "Sorry, node " + to_string(finish) + " is not reachable from node " + to_string(start) + ".";
        return str;
    }
    if(flag == 0){
        Vertex v = S[s_size];
        str = "LENGTH: " + to_string(v.get_distance());
    }

    if(flag == 1){
        Vertex* v = &S[s_size];
        str = to_string(v->get_index());
        while(v->get_previous() != 0){
            v = v->get_previous();
            str = to_string(v->get_index()) + ", " + str;
        }
        str = "PATH: " + str;
    }
    //psuedo code
    //initialize single source
    //S = empty set
    //Q = G.V
    //while Q is not empty set
    //  u = Extract-min(Q)
    //  S = S union {u}
    //  for each vertex v in G.Adj[u]
    //      Relax(u,v,w)



    return str;
}


 Vertex* Graph::initialize_single_source(int start){
    Vertex* v_set = new Vertex[n + 1]; //create Vertex for each vertex in Graph
    for(int i = 1; i <= n; i++){
        v_set[i].set_index(i);
        v_set[i].set_edges(edges[i]); //edges should not be modified after being set
        v_set[i].set_distance(2147483647);
        v_set[i].set_previous(0);
    }
    v_set[start].set_distance(0);
    return v_set;
    //psuedo code
    //for each vertex v in G.V
    //  v.d = inf
    //  v.prev = NIL
    //s.d = 0

}



int Graph::get_n(){
    return this->n;
}



