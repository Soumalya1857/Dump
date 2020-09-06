#include<iostream>
using namespace std;

int main()
{
    int n,i,count = 1, result = 0, q,x,cnt;
    cout << "Enter the number: ";
    cin >> n;
    int a[n+1],b[n+1];
    q = n;
    for(i=1;i<=n;i++)
    {
        a[i] = q%10;
        x = a[i];
        while(x!=0)
        {
            b[i]= b[i] * x;
            x--;
        }
        cout << "fact: " << a[i] << " =" << b[i] << "\n";
        q/=10;
        result += b[i];
    }
    cout << "result: " << result << endl;
    if(result == n) cout << "strong\n";
    else cout << "Not strong\n";

    return 0;
}