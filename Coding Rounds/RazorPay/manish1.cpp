#include<bits/stdc++.h>
using namespace std;


void solve(int N, int M, int A, int B)
{
    int res = 0;
    double spec = M/(B*1.0);
    if(spec >= A)
    {
        int num = N/M;
        res = num*B + (N % M)*A;
    }
    else 
        res = N * A;

    cout << res;
}

int main()
{
    solve(6,2,1,6);
    return 0;
}