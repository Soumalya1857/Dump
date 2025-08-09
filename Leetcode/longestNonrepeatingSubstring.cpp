#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        
        int index[256];
        //cout << "index done\n";
        for(int i=0;i<256;i++) index[i] = -1;
        int count = 0;
        int maxi = 0;
        int i,j;
        i=0;
        //cout << "done\n";
        for(j=0; j < s.length(); j++)
        {
            //last occurance of s[j]
            
            i = max(i, index[s[j]]+1);
            // window size = j-i+1.
            maxi = max(maxi, j-i+1);
            index[s[j]] = j;
        }
        return maxi;
    }


int main()
{
    string s = "soumalya";
    cout << s << endl;
    int res = lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}