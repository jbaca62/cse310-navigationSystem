#include "Vertex.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Vertex::Vertex()
{
    index = 0;
   distance = 0;
   previous = 0;
}

Vertex::Vertex(int d){
    distance = d;
}

void Vertex::relax(Vertex* v, int weight){
    if(v->distance > this->distance + weight){
        //cout << "Relaxing vertex " << v->get_index() << endl;
        v->distance = this->distance + weight;
        v->previous = this;

        //cout << "Vertex " << v->index << " previous: " << v->previous->get_index() << endl;
    }
    //psuedo cod
    //if v.d > u.d + w(u, v)
    //  v.d = u.d + w(w, v)
    //  v.prev = u
}

bool Vertex::contains(Vertex* v, int s, int index){
    for(int i = 1; i <= s; i++){
        if(v[i].get_index() == index){
            return true;
        }
    }
    return false;
}

Edge* Vertex::get_edges(){
    return edges;
}

int Vertex::get_index(){
    return index;
}

Vertex* Vertex::get_previous(){
    return previous;
}

void Vertex::set_index(int i){
    index = i;
}

void Vertex::set_edges(Edge* e){
    edges = e;
}

void Vertex::set_distance(int d){
    distance = d;
}

void Vertex::set_previous(Vertex* p){
    previous = p;
}

int Vertex::get_distance(){
    return distance;
}

void Vertex::print_vertices(Vertex* v, int s){

    for(int i = 1; i <= s; i++){
        Vertex V = v[i];
        if(V.get_previous() != 0){
        printf("Index: %d Distance: %d Previous: %d\n", V.get_index(), V.get_distance(), V.get_previous()->get_index() );
        }
        else{
            printf("Index: %d Distance: %d Previous: %d\n", V.get_index(), V.get_distance(), 0 );
        }
    }
}
