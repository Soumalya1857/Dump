
#include<bits/stdc++.h>
using namespace std;
// class Solution {
    
// public:
//     //manacher's algo
    string convertString(string s){
        string res = "$";
        for(char c: s) res += c, res += "$";
        return res;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        
        string ss  = convertString(s);
        int c = 0, r = 0;
        int ansc = 0, anslen = 0;
        vector<int> res(ss.size(),0); 
        for(int i=1;i<ss.size()-1;i++){
            res[i] = i < r ? min(r-i,res[c-(i-c)]) : 1;
            while(i-res[i]>=0 && i+res[i]<ss.size() && ss[i-res[i]]==ss[i+res[i]]) res[i]++;
            res[i]--;
            if(i + res[i] > r) r = res[i], c = i;
            if(res[i] > anslen) anslen = res[i],ansc=i;
        }
        return s.substr((ansc-anslen)/2,anslen);
    }


string manacher(string s)
{
    string res = "#";
    for(char c : s)
    {
        res += c;
        res += "#";
    }

    int len = res.length(),i;
    int p[len];
    for(i=0;i<len;i++) p[i] = 0;
    int center = 0, right = 0;

    for(int i=1; i< len; i++)
    {
        int mirror = (2*center-i > 0)? (2*center-i): 1;
        if (i < right)
        {
            p[i] = min(right-i, p[mirror]);
        }

        while(res[i + (1+p[i])] == res[i-(1+p[i])]) p[i]++;
        if(1+p[i] > right) 
        {
            center = i;
            right = i + p[i];
        }
    }
    int length = -1,anscenter = -1;
    //string ans = "";
    for(int i=0;i<len;i++)
    {
        if(p[i] > length)
        {
            length = p[i];
            anscenter = i;
        }
    }
    //return s.substr((anscenter-length)/2, length);
     string ans = "";
        for(i=(anscenter-length)/2; i< (anscenter+length)/2;i++)
        {
            ans += s[i];
        }
        return ans;


}

// };
// Comment



/****

https://leetcode.com/problems/longest-palindromic-substring/
*****/

// dp solution of 0(n^2)
// string longestPalindrome(string s) {
        
//         int len = s.length();
//         bool dp[len+1][len+1];
//         int i,j;
//         int maxi=-1,maxj=-1,maxlen = -1,count = 1;
//         for(i=0;i<=len;i++)
//         {
//             for(j=0;j<=len;j++)
//             {
//                 dp[i][j] = false;
//             }
//         }
//         for(i=0;i<=len;i++) dp[i][i] = true;
//         for(i=0;i< len-1;i++) if(s[i] == s[i+1]) dp[i][i+1] = true;
        
//         for(int k=3;i<=len;k++)
//         {
//             for(i=1;i<=len-k+1;i++)
//             {
//                 j = i+k-1;
//                 cout << "bla " << count++ << "\n";
//                 if(s[i]==s[j] && dp[i+1][j-1]) 
//                 {
//                     dp[i][j] = true; 
//                     //int l = j-i+1;
//                     if(k > maxlen)
//                     {
//                         maxlen = k;
//                         maxi = i;
//                         //maxj = j;
//                     }
//                 }
//             }
//         }
//         string res = "";
//         for(i=maxi;i<=maxi+maxlen-1;i++)
//         {
//            res += s[i]; 
//         }
//         return res;
        
//     }

    int main()
    {
        string s = "geeeegksmam";
        string res = manacher(s);
        cout << res << endl;
        return 0;
    }


    /****
    https://www.youtube.com/watch?v=nbTSfrEfo6M

    follow for explanation
    
    ***/



