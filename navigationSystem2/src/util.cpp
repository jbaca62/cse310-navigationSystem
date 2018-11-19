#include <iostream>
#include <fstream>
#include "Element.h"
#include "Edge.h"

using namespace std;

int nextCommand(int *i, int *v, int *f)
{
    char c;
    while(1){
        scanf("%c", &c);
        if(c == ' ' || c == '\t' || c == '\n'){
            continue;
        }
        if(c == 'S' || c == 'W'){
            break;
        }
        if(c == 'R' || c == 'r'){
            break;
        }
        if(c == 'P' || c == 'p'){
            scanf("%d", i);
            scanf("%d", v);
            scanf("%d", f);
            break;
        }
    }
    return c;
}

//reads from
Edge* read_input_text(){
    ifstream text_file("Ginput.txt");
    if(!text_file.is_open()){
        cout << "There was a problem opening file Ginput.txt for reading." << endl;
        return 0;
    }
    int n_size;
    int m_size;
    text_file >> n_size;
    text_file >> m_size;
    Edge* vertices = new Edge[n_size +1];
    vertices[0].set_index(n_size);
    vertices[0].set_weight(m_size);
    for(int i = 1; i <= m_size; i++){
        if(text_file.eof()){
            cout << "Sorry!!! It cannot be done. The number of elements in the file is less than as specified in the beginning of the file." << endl;
            return 0;
        }
        int u, v, w;
        text_file >> u;
        text_file >> v;
        text_file >> w;
        vertices[u].add_edge(v, w);
    }
    text_file.close();
    return vertices;

}
