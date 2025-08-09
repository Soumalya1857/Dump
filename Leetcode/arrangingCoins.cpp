#include<bits/stdc++.h>
using namespace std;

long long number(long long n)
    {
        long long ans = (n*(n+1))/2;
        return ans;
    }
    int arrangeCoins(int n) {
        int low = 1;
        int high = 92681;
        int ans = 0;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(number(mid) == n) {high = mid;break;}
            if(number(mid) > n)
            {
                //ans = mid-1;
                high = mid-1;
            }
            if(number(mid) < n)
            {
                low = mid+1;
            }
        }
        return high;
    }

int main()
{
    int n;
    cin >> n;
    cout <<  arrangeCoins(n) << endl;
    return 0;
}