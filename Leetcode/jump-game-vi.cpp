// dp + memo (runtime error)

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        vector<long long> dp(nums.size(), INT_MIN);
        // dp[i] max cost with arr i to end
        return solve(nums,dp,k,0);
    }

    int solve(vector<int>&nums, vector<long long>&dp, int k, int index){
        
        if(index == nums.size()-1)
            return nums[nums.size()-1];

        if(dp[index] != INT_MIN) return dp[index];

        int size = nums.size();
        
        for(int i = index+1; i < min(index+k, size-1);i++){
            dp[index] = max(dp[index], (long long)(nums[index] + solve(nums,dp,k,i)));
        }

        return dp[index];
    }
};


// https://leetcode.com/problems/jump-game-vi/solutions/1260737/optimizations-from-brute-force-to-dynamic-programming-w-explanation/




///// priority queue solution 