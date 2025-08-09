class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
     
        /*https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/788530/DP-solution*/
        
        
        // dp[i][0] = swap not needed for ith step
        // dp[i][1] = swap needed for ith step
        
        int n = A.size();
        int dp[n][2];
        for(int i=0;i<n;i++)
        {
            dp[i][0] = INT_MAX;
            dp[i][0] = INT_MAX;
        }
        
        dp[0][0] = 0;
        dp[0][1] = 1;
        
        for(int i=1;i<n;i++)
        {
            if(A[i-1] < A[i] && B[i-1] < B[i])
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;// ager ta flip korle etao flip korte hobe
            }
            
            if(A[i-1] < B[i] && B[i-1] < A[i])
            {
                dp[i][0] = min(dp[i][0],dp[i-1][1]);// ager if stat update koreche
                                            // dp[i][0] thats why min
                                            // but actually dp[i-1][1]
// age flip hoyeche...ekhon hoyni 
                
                dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
                // either ekhon flip kora hocche or age flip hoyni ekhon hocche 
            }
        }
        
        return min(dp[n-1][0], dp[n-1][1]);
    }
};

###############################################################################################


