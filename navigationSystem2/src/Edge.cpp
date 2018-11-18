#include <iostream>
#include "Edge.h"

using namespace std;

Edge::Edge()
{
    index = 0;
    weight = 0;
    next = 0;
}
Edge::Edge(int i, int w){
    index = i;
    weight = w;
    next = 0;
}

void Edge::add_edge(int i, int w){
    if(index == 0){
        index = i;
        weight = w;
    }
    else if(next == 0){
        cout << "Edge.next is 0" << endl;
        next = new Edge(i, w);
    }
    else{
        next->add_edge(i, w);
    }
}

int Edge::get_index(){
    return index;
}

int Edge::get_weight(){
    return weight;
}

Edge* Edge::get_next(){
    return next;
}

void Edge::set_index(int i){
    index =i;
}

void Edge::set_weight(int w){
    weight = w;
}
