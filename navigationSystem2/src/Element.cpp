#include "Element.h"

Element::Element()
{
    this->key = 0;
}

Element::Element(int k){
    key = k;
}

int Element::get_key(){
    return key;
}
int Element::get_index(){
    return index;
}

void Element::set_key(int k){
    key = k;
}

void Element::set_index(int i){
    index = i;
}



