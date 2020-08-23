#include<bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int,int> m;
    m.insert({6,40});
    m.insert({6,60});
    m.insert({7,43});


    cout << m[6] << endl;
    return 0;
}