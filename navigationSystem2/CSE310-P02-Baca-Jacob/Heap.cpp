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

Heap::Heap(int c, int s, Vertex *v){
    this->capacity = c;
    this->size = s;
    this->H = v;
}

 Heap Heap::initialize(int n, Vertex* v){
    Heap newHeap = Heap();
    newHeap.capacity = n;
    newHeap.size = 0;
    newHeap.H = v;
    return newHeap;
}

void Heap::min_heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest;
    if(l <= size && H[l].get_distance() < H[i].get_distance()){
        smallest = l;
    }
    else{
        smallest = i;
    }
    if(r <= size && H[r].get_distance() < H[smallest].get_distance()){
        smallest = r;
    }
    if(smallest != i){
        Vertex temp = H[i];
        H[i] = H[smallest];
        H[smallest] = temp;
        this->min_heapify(smallest);
    }
}

void Heap::build_heap(Vertex* v, int n, int flag){
    size = n;
    //H = v;
    //insert all elements into heap
//    for(int i = 1; i <= size; i++){
//        H[i].set_index(i);
//        H[i].set_distance(v[i].get_distance());
//        H[i].set_edges(v[i].get_edges());
//        H[i].set_previous(0);
//    }
    for(int i = (size/2); i >= 1; i--){
        this->min_heapify(i);
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
        int key = (H + i)->get_distance();
        int index = H[i].get_index();
        printf("Index: %d Distance: %d \n", index, key);
    }
}

void Heap::decrease_key(int i, int k, int f){
    if(size < i){
        printf("There are only %d elements in the heap. Hence this operation cannot be completed.\n", size);
    }
    if(k > H[i].get_distance()){
       printf("new key is larger than current key");
    }
    if(f == 1){
        print_heap();
    }
    H[i].set_distance(k);
    while(i > 1 && H[parent(i)].get_distance() < H[i].get_distance()){
        Vertex temp = H[i];
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
        Vertex* e = new Vertex[capacity];
        for(int i = 1; i <= size - 1; i++){
            e[i] = H[i];
        }
        delete H;
        this->H = e;
    }
    H[size] = Vertex();
    this->decrease_key(size, k, 0);
    if(flag == 1){
        print_heap();
    }
}

Vertex Heap::delete_min(int flag){
    if(flag == 1){
        this->print_heap();
    }
    if(size < 1){
        cout << "There are no elements in the heap to delete." << endl;
        return Vertex(-2147483646);
    }
    Vertex e = H[1];
    H[1] = H[size];
    size--;
    this->min_heapify(1);
    if(flag == 1){
        this->print_heap();
    }
    return e;
}

//bool Heap::add_element(Element newElement, int i){
//    Vertex* e = (H + i);
//    //will
//    *e = newElement;
//    size++;
//
//    return true;
//
//}

//returns the vertex with the specified index
Vertex* Heap::get_vertex(int index){
    for(int i = 1; i <= size; i++){
        if(H[i].get_index() == index)
            return &H[i];
    }
    return 0;
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

void Heap::set_H(Vertex* e){
    H = e;
}

int Heap::get_capacity(){
    return capacity;
}

int Heap::get_size(){
    return size;
}

Vertex* Heap::get_H(){
    return H;
}
