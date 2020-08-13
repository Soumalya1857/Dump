#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007
#define MOD1 998244353

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;

int main() 
{ 
    love you codechef
    register ll i,j;
    TEST
    {
        ll n;
        cin >> n;
        ll a[n];
        for(i=0;i<n;i++) cin >> a[i];

        ll max_area = 0,i=0;
        ll area = 0;
        ll top = 0;
        stack<ll> s;
        while(i<n)
        {
            if(s.empty() || a[s.top()] <= a[i]) s.push(i),i++;
            else
            {
                top = s.top();
                s.pop();
                area/*assuming s.top()is the min object*/ = a[top] * (s.empty()? i : i-s.top()-1);
                max_area = max(area,max_area);
            }    
        }
        while(!s.empty())
        {
            top = s.top();
            s.pop();
            area = a[top] * (s.empty()? i : i-s.top()-1);
            max_area = max(area,max_area);       
        }
        cout << max_area << endl;

    }
    return 0;
}

/**********
 * 
 * https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
 * 
 * 
 * 1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
    Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. 
    For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
 * 
 * ********/