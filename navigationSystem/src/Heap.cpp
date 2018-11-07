#include "Heap.h"
#include <iostream>
#include <math.h>

using namespace std;

Heap::Heap()
{
    capacity = 0;
    size = 0;
    H = 0;
}

Heap::Heap(int c, int s, Element *h){
    this->capacity = c;
    this->size = s;
    this->H = h;
}

 Heap Heap::initialize(int n){
    Heap newHeap = Heap();
    newHeap.capacity = n;
    newHeap.size = 0;
    newHeap.H = new Element[n + 1];
    return newHeap;
}

void Heap::max_heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= size && H[l].get_key() > H[i].get_key()){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= size && H[r].get_key() > H[largest].get_key()){
        largest = r;
    }
    if(largest != i){
        Element temp = H[i];
        H[i] = H[largest];
        H[largest] = temp;
        this->max_heapify(largest);
    }
}

void Heap::build_heap(Element a[], int n, int flag){
    size = n;
    //insert all elements into heap
    for(int i = 1; i <= size; i++){
        H[i] = a[i];
    }
    for(int i = (size/2); i >= 1; i--){
        this->max_heapify(i);
        if(flag == 2){
            print_heap();
        }
    }
    if(flag == 1){
        print_heap();
    }
}

void Heap::print_heap(){
    printf("The capacity is %d.\n", this->capacity);
    printf("The size is %d.\n", this->size);
    for(int i = 1; i <= this->size; i++){
        int key = (H + i)->get_key();
        printf("%d\n", key);
    }
}

void Heap::increase_key(int i, int k, int f){
    if(size < i){
        printf("There are only %d elements in the heap. Hence this operation cannot be completed.\n", size);
    }
    if(k < H[i].get_key()){
       // printf("new key is smaller than current key");
    }
    if(f == 1){
        print_heap();
    }
    H[i].set_key(k);
    while(i > 1 && H[parent(i)].get_key() < H[i].get_key()){
        Element temp = H[i];
        H[i] = H[parent(i)];
        H[parent(i)] = temp;
        i = parent(i);
    }
    if(f == 1){
        print_heap();
    }
}

void Heap::heap_insert(int k, int flag){
    if(flag == 1){
        print_heap();
    }
    size++;
    if(this->size > this->capacity){
        this->capacity = pow(2, floor(log(size)/log(2)) + 1);
        Element* e = new Element[capacity];
        for(int i = 1; i <= size - 1; i++){
            e[i] = H[i];
        }
        delete H;
        this->H = e;
    }
    H[size] = Element(
                       );
    this->increase_key(size, k, 0);
    if(flag == 1){
        print_heap();
    }
}

Element Heap::delete_max(int flag){
    if(flag == 1){
        this->print_heap();
    }
    if(size < 1){
        cout << "There are no elements in the heap to delete." << endl;
        return Element(-2147483646);
    }
    Element e = H[1];
    H[1] = H[size];
    size--;
    this->max_heapify(1);
    if(flag == 1){
        this->print_heap();
    }
    return e;
}

bool Heap::add_element(Element newElement, int i){
    Element* e = (H + i);
    //will
    *e = newElement;
    size++;

    return true;

}

int Heap::parent(int i){
    int x = i / 2;
    return x;
}

int Heap::left(int i){
    return 2*i;
}

int Heap::right(int i){
    return 2*i+1;
}

void Heap::set_H(Element* e){
    H = e;
}

int Heap::get_capacity(){
    return capacity;
}
