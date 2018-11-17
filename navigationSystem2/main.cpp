#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Heap.h"
#include "Element.h"

using namespace std;

int main()
{
    Heap heap;
    heap = Heap::initialize(5);
    bool heap_is_initialized = true;
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
                cout << "The program is going to be terminated." << endl;
                exit(0);

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
                //will need to be changed to print graph
                heap.print_heap();
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

            case 'P':
                printf("COMMAND: %c %d %d %d", c, i, v, f);
                cout << "Command not written" << endl;
                continue;
            case 'p':
                printf("COMMAND: %c %d %d %d", c, i, v, f);
                cout << "Command not written" << endl;
                continue;

            default:
              break;


        }
    }
    exit(0);
}
