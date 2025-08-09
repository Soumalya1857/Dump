class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
//         int m = text1.length();
//         int n = text2.length();
        
//         int dp[n+1][m+1];// dp[i][j] = lcs upto[0...i-1][0...j-1]
        
//         for(int i=0;i<=n;i++)dp[i][0]=0;
//         for(int i=0;i<=m;i++)dp[0][i]=0;
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 //if(i==0 || j==0) dp[i][j] = 0;
//                 if(text1[i-1] == text2[j-1]) 
//                 {
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
        
        // for printing lowest common subsequence
        // int i=n,j=m;
        // while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
        //     if(x[i-1]==y[j-1]){
        //         s+=x[i-1];    //if character matches then add that to result string and move diagonally up
        //         i--;j--;
        //     }
        //     else{
        //         if(dp[i][j-1]>dp[i-1][j])j--;    // else find the max of up and right position of dp table and move accordingly to up or left
        //         else i--;
        //     }
        // }
        // reverse (s.begin(),s.end());    // reverse the string as we started from last
        // cout<<s;
 
        //int maxi = -1;
        
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         if(dp[i][j] > maxi) maxi = dp[i][j];
        //     }
        // }
        
        //return maxi;
        
        
        
        
        int n=text1.size(),m=text2.size();
        //string s;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
        
    }
};


/*
https://leetcode.com/problems/longest-common-subsequence/

sol- https://leetcode.com/problems/longest-common-subsequence/discuss/774573/C%2B%2B-DP-solution-98-or-with-Printing-the-Lowest-Common-Subsequence
*/