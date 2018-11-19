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

void Element::set_key(int k){
    key = k;
}

