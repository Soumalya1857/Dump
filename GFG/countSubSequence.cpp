/***
 * 
 * Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc
 * ***/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int a=0,b=0,c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a') a = 1+2*a;//new count=previous count+
                // we can append 'a' to all previous strings ending with 'a'+
                //we can start new subsequence starting with 'a'
            else if(s[i]=='b') b = a+2*b;// 2*b same as 2*a
                    // we can add b to every sequence ends with a
            else if(s[i]=='c') c = b + 2*c;//same as b
        }
        cout << c << endl;
    }
    return 0;
}