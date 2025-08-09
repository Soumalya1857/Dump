class Solution {

private:
    int getVal(vector<int> &nums, int k){
        if(k<0 || k== nums.size()){
            return 1;
        }

        return nums[k];
    }
    int solve(vector<int> &nums, int left, int right, vector<vector<int>> &dp){
        if(left > right){
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int maxi = INT_MIN;
        for(int k=left; k<=right; k++){
            int tempVal = solve(nums, left, k-1, dp) + solve(nums, k+1, right, dp)
                            + getVal(nums,left-1)*getVal(nums,k)*getVal(nums,right+1); // why? see: https://youtu.be/Yz4LlDSlkns?si=DAnWHmVpd26pWbFr

            maxi = max(maxi, tempVal);
        }

        return dp[left][right] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        // going through Aditya verma concept

        // i = 0 and j=n-1
        // k is from i to j

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return solve(nums, 0, nums.size()-1, dp);


    }
};

// https://leetcode.com/problems/burst-balloons/submissions/1309757564/
// https://youtu.be/Yz4LlDSlkns?si=DAnWHmVpd26pWbFr  <<== Gawd explanation
// down se DP start karo then we will not get interdependent sub-problems