
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
};

class derived: public base
{
    public:

        // double add(double a, double b)
        // {
        //     return a+b+5;
        // }

        void show(){cout << "blablabla\n";}
};


int main()
{
    base b;
    derived d;

    cout << "b.add(5,3):" << " ";
    cout << b.add(5,3) << endl;

    cout << "d.add(5.3,3.2): " << " " << d.add(5.3f,3.2f) << endl;

    return 0;
}