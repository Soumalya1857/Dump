class Solution {
public:
    int solve(vector<int> &nums, int target, vector<int> &dp){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int total = 0;
        for(int num : nums){
            int val = solve(nums, target-num, dp);
            if(val != 0){
                total += val;
            }
        }

        return dp[target] = total;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return solve(nums, target, dp);
    }
};

// https://leetcode.com/problems/combination-sum-iv/