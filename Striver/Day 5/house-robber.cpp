class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] max value i can get upto i th house
        
        int size = nums.size();
       // vector<int> dp(size,0);
        if(size == 1) return nums[0];
//         dp[0] = nums[0];
//         dp[1] = max(dp[1], max(dp[0], nums[1]));
        
//         for(int i=2;i<size;i++)
//         {
//             dp[i] = max(dp[i], max(dp[i-1], dp[i-2]+nums[i]));
//         }
        //return dp[size-1];
        
        // we are only using dp[i],dp[i-1],dp[i-2] => state minimization possible
        
        int dpi=-1,dpi1=-1,dpi2=-1, maxRob = -1;
        
        dpi2 = nums[0];
        dpi1 = max(dpi1,max(dpi2,nums[1]));
        maxRob = max(dpi2,dpi1);
        
        for(int i=2;i<size;i++)
        {
            dpi = max(dpi, max(dpi1, dpi2+nums[i]));
            maxRob = max(maxRob,dpi);
            
            dpi2 = dpi1;
            dpi1 = dpi;
        }
        return maxRob;
        
    }
};

// prob: https://leetcode.com/problems/house-robber/submissions/