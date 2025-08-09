#include<iostream>
using namespace std;

int add(int a, int b, int c)
{
    return (int)(a+b);
}


double add(float a, float b)
{
    return a+b+5;
}
int main()
{

    cout << add(3.6,5.2) << endl;
    return 0;
}