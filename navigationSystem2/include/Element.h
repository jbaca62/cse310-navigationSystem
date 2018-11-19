#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element();
        Element(int);
        int get_key();
        void set_key(int);


    protected:

    private:
        int key;
};

#endif // ELEMENT_H
