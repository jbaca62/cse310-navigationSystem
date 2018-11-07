#include <iostream>
#include <fstream>
#include "Element.h"

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
        if(c == 'D' || c == 'd'){
            scanf("%d", i);
            break;
        }
        if(c == 'R' || c == 'r'){
            scanf("%d", f);
            break;
        }
        if(c == 'K' || c == 'k'){
            scanf("%d", i);
            scanf("%d", v);
            scanf("%d", f);
            break;
        }
        if(c == 'C'|| c == 'c'){
            scanf("%d", i);
            break;
        }
        if(c == 'I' || c == 'i'){
            scanf("%d", i);
            scanf("%d", f);
            break;
        }

    }
    return c;
}

//reads from
Element* read_input_text(){
    ifstream text_file("HEAPinput.txt");
    if(!text_file.is_open()){
        cout << "There was a problem opening file HEAPinput.txt for reading." << endl;
        return 0;
    }
    int a_size;
    text_file >> a_size;
    Element* e = new Element[a_size + 1];
    e[0].set_key(a_size);
    for(int i = 1; i <= a_size; i++){
        if(text_file.eof()){
            cout << "Sorry!!! It cannot be done. The number of elements in the file is less than as specified in the beginning of the file." << endl;
            return 0;
        }
        int x;
        text_file >> x;
        e[i] = Element(x);
    }
    text_file.close();
    return e;

}
