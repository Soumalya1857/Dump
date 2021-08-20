
#include<iostream>
using namespace std;

class base
{
    public:
        int add(int a, int b)
        {
            return a+b;
        }

        double add(double a, double b)
        {
            return a+b+5;
        }

        float add(float a, float b)
        {
            return a+b+10;
        }
        void prints(int a) {cout << "prints\n";}
        void print(int a){cout << "this is base class\n";}
};

class derived: public base
{
    public:

        // double add(double a, double b)
        // {
        //     return a+b+5;
        // }

        void show(){cout << "blablabla\n";}

        void print(){cout << "This is derived class\n";}
};


int main()
{
    base b;
    derived d;

    // cout << "b.add(5,3):" << " ";
    // cout << b.add(5,3) << endl;

    // cout << "d.add(5.3,3.2): " << " " << d.add(5.3f,3.2f) << endl;
    base* bptr = &d;
    //bptr->print();
    d.print(5);

    return 0;
}

// points to remember:

/*
1) for runtime polymorphism signature has to be same
2) it is better to make destructor virtual in base class to avoid undefined behavior link: https://www.youtube.com/watch?v=4z9pPkHLBio
3) if virtual function signature doesn't match in derived class and we try to call derived func with base ptr=> we will get error
4) if signature doesn't match in derived class, and we try to call base's virtual func using derived object => we will get errror
5) base class derived class func overloading not allowed! Derived class will check if the called func is defined inside it or not. Then will
    throw an error. It won't check the base class.
6) base class can hold child objects but only have access to own functions and those whose are overrided in child with same signature
7) virtual constructor is not possible... as vptr points to vtable in consturctor
*/