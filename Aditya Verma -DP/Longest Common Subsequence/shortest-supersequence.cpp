#include<bits/stdc++.h>
using namespace std;

static int dp[100][100];
// this will give me the length 
int shortestSubSeq(string a, string b, int m, int n)
{
    if(m == 0) return n;
    if(n == 0) return m;

    if(dp[m][n] != -1) return dp[m][n];

    if(a[m-1] == b[n-1]) 
        return dp[m][n] = 1 + shortestSubSeq(a,b,m-1,n-1);

    else 
        return dp[m][n] = 1 + min(shortestSubSeq(a,b,m-1,n) , shortestSubSeq(a,b,m,n-1)); // if not match include the letter to string and then check to m-1,n and m,n-1    }
}

// a = abbc
// b = bbeck
string traceBack(string a, string b, int m, int n)
{
    int i=m,j=n;
    string res = "";

    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1]){
            res += a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1])
            {
                res += b[j-1];
                j--;
            }
            else {
                res += a[i-1];
                i--;
            }
        }
    }

    while(i>0) res += a[i-1],i--;
    while(j>0) res += b[j-1],j--;

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a = "geeks";
    string b = "eke";

    memset(dp,-1,sizeof(dp));
    cout << shortestSubSeq(a,b,a.length(),b.length()) << endl;
    cout << traceBack(a,b,a.length(), b.length()) << endl;
    return 0;
}