#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Heap.h"
#include "Element.h"
#include "Graph.h"

using namespace std;

int main()
{
    Graph graph;
    bool graph_is_initialized = false;
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
                graph.print_graph();
                continue;
            case 'W':
                printf("COMMAND: %c.\n", c);
                if(!graph_is_initialized){
                    cout << "Sorry!!! It cannot be done. Please initialize the graph first." << endl;
                    break;
                }
                //will need to be changed to print graph
                graph.print_graph();
                continue;

            case 'R':
                {
                printf("COMMAND: %c.\n", c);
                //heap.build_heap(e, 4, i);
                Edge* v = read_input_text();
                if(v == 0){
                    break;
                }
                int n_size = v[0].get_index();
                int m_size = v[0].get_weight();
                graph = Graph::initialize(n_size, m_size);
                graph.build_graph(n_size, m_size, v);
                }
                graph_is_initialized = true;
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
