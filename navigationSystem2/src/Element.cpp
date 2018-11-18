#include "Element.h"

Element::Element()
{
    this->next = 0;
}

Element::Element(int i){
    index = i;
}

Element::Element(int u , int v, int w){
    index = u;
    weight = w;
    next_index = v;
    next = 0;
}

int Element::get_index(){
    return index;
}

int Element::get_weight(){
    return weight;
}

int Element::get_next_index(){
    return next_index;
}

void Element::set_next(Element *n){
    next = n;
}

void Element::set_weight(int w){
    weight = w;
}

void Element::set_index(int i){
    index = i;
}

void Element::set_next_index(int i){
    next_index = i;
}

