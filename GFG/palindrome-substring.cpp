
// User function Template for C++

class Solution {
  public:
    int CountPS(char s[], int n) {
        // code here

        vector<vector<bool>> dp(n, vector<bool> (n,false));
        int ans = 0;


        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }

        // check for all the gaps
        for(int gap=2; gap<=n; gap++){
            // starting point
            for(int start = 0; start<=n-gap; start++){
                int end = start+gap-1;


                // if gap is 2
                if(gap==2){
                    dp[start][end] = (s[start] == s[end]);
                }else{

                    dp[start][end] = ((s[start] == s[end]) & dp[start+1][end-1]);
                }


                if(dp[start][end]){
                    ans++;
                }


            }
        }


        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/