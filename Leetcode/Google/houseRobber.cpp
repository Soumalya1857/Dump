class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        //vector<bool> robbed(n,false); // true means house is robbed
        
        
           int dp[n];
//         for(int i=0;i<n;i++) dp[i] = 0; // max robbed amount after robbing ith house
        
        
//         if(robbed[i-1] == true) dp[i] = dp[i-1];
//         if(robbed[i-1] == false) {
//             dp[i] = max(dp[i-1], dp[i-1]+)
//         }
        
        
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        
        return dp[n-1];
        
        // follow knapsack problem
        // https://www.youtube.com/watch?v=8LusJS5-AGo&t=24s

        // Q=> https://leetcode.com/problems/house-robber
    }
};