#pragma once

struct my_class

{
    int field;
    int add(int x, int y);

    public:

    protected:

    private:

};

class my_class1
{
    int field1;

    
    public:
        my_class1();
        ~my_class1();
        my_class1(const my_class1& other);
        my_class1(my_class1&& other);
        my_class1& operator=(const my_class1& other);
        my_class1& operator=(my_class1&& other);
        // правила 0, 3 и 5
         




    protected:
    private:

};