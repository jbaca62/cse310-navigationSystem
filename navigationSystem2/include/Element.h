#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element();
        Element(int);
        int get_key();
        int get_index();
        void set_key(int);
        void set_index(int);

    private:
        int key;
        int index;
};

#endif // ELEMENT_H
