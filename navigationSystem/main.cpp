#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Heap.h"
#include "Element.h"

using namespace std;

int main()
{
    //Element e[5] = {Element(0), Element(1), Element(2), Element(3), Element(4)};
    Heap heap;
    bool heap_is_initialized = false;
    // varialbles for the fparser...
    char c;
    int i, v, f;
    while(1){
        c = nextCommand(&i, &v, &f);
        switch(c){
            case 's':
                printf("COMMAND: %c.\n", c);
                cout << "The program is going to be terminated." << endl;
                exit(0);
            case 'S':
                printf("COMMAND: %c.\n", c);
                exit(0);

            case 'k':
                printf("COMMAND: %c %d %d.\n", c, i, v);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the values into it." << endl;
                    break;
                }
                heap.increase_key(i,v,f);
                continue;
            case 'K':
                printf("COMMAND: %c %d %d %d.\n", c, i, v, f);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the values into it." << endl;
                    break;
                }
                heap.increase_key(i,v,f);
                continue;

            case 'w':
                printf("COMMAND: %c.\n", c);
                heap.print_heap();
                continue;
            case 'W':
                printf("COMMAND: %c.\n", c);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first." << endl;
                    break;
                }
                heap.print_heap();
                continue;

            case 'c':
                printf("COMMAND: %c %d.\n", c, i);
                heap = Heap::initialize(i);
                heap_is_initialized = true;
                continue;
            case 'C':
                printf("COMMAND: %c %d.\n", c, i);
                heap = Heap::initialize(i);
                heap_is_initialized = true;
                //heap.add_element(Element(2), 1);
                //heap.add_element(Element(3), 2);
                continue;

            case 'i':
                printf("COMMAND: %c %d %d.\n", c, i, f);
                heap.heap_insert(i, f);
                continue;
            case 'I':
                printf("COMMAND: %c %d %d.\n", c, i, f);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first." << endl;
                    break;
                }
                heap.heap_insert(i, f);
                continue;

            case 'd':
                printf("COMMAND: %c %d.\n", c, i);
                heap.delete_max(i);
                continue;
            case 'D':
                {
                printf("COMMAND: %c %d.\n", c, i);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it." << endl;
                    break;
                }
                Element e = heap.delete_max(i);
                if(e.get_key() != -2147483646){
                    printf("%d\n", e.get_key());
                }

                }
                continue;

            case 'R':
                {
                printf("COMMAND: %c %d.\n", c, f);
                if(!heap_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the heap first." << endl;
                    break;
                }
                //heap.build_heap(e, 4, i);
                Element* e = read_input_text();
                if(e == 0){
                    break;
                }
                int e_size = e[0].get_key();
                if(e_size > heap.get_capacity()){
                    printf("Sorry!!! It cannot be done. Please increase the capacity of the heap first.\n");
                    break;
                }
                heap.build_heap(e, e_size, f);
                delete e;
                }
                continue;

            default:
              break;


        }
    }
    exit(0);
}
