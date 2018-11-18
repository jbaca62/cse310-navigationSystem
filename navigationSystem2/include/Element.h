#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element();
        Element(int);
        Element(int, int, int);
        int get_index();
        int get_weight();
        int get_next_index();
        void set_next(Element*);
        void set_weight(int);
        void set_index(int);
        void set_next_index(int);


    protected:

    private:
        int index;
        int weight;
        int next_index;
        Element *next;

};

#endif // ELEMENT_H
