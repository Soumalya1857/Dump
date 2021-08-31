#include<iostream>
using namespace std;


int main()
{
    int p=8, q=7, r=5;
    if((p^7 )<(6+p)) 
    {
        p = (12)+p;
        q = (p&7)+q;
    }
    cout << p + q+r << endl;
    return 0;
}