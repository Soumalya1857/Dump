class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        dp.resize(n, vector<int>(n));
        return helper(nums,1,n-1);
    }
    int helper(vector<int>& nums,int start,int end){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != 0){
            return dp[start][end];
        }
        int res = INT_MIN;
        for(int k = start; k < end; k++){
            int temp = helper(nums,start,k) + helper(nums,k+1,end) + nums[start-1]*nums[k]*nums[end];
            res = max(res,temp);
        }
        dp[start][end] = res;
        return res;
    }
};

/*
matrix chain multiplication this is
https://leetcode.com/problems/burst-balloons/
https://leetcode.com/problems/burst-balloons/discuss/829516/C%2B%2B-Based-On-Matrix-Chain-Multiplication
*/