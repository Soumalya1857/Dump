class Solution {
private:
    bool isFirstEligible(vector<int> &nums, int index){
        if(nums.size() - index < 2) return false;

        return nums[index] == nums[index+1];
    }

    bool isSecondEligible(vector<int> &nums, int index){
        return (nums.size() - index >= 3) && (nums[index] == nums[index+1]) && (nums[index+1] == nums[index+2]);
    }

    bool isThirdEligible(vector<int> &nums, int index){
        return (nums.size() - index >= 3)
                && (nums[index]+1 == nums[index+1] )
                    && (nums[index+1] + 1 == nums[index+2]);

    }


    bool solve(vector<int> &nums, int index, vector<int> &dp){
        if(index >= nums.size()){
            return true;
        }

        if(dp[index] != -1) return dp[index];

        bool first = isFirstEligible(nums, index) && solve(nums, index+2, dp);
        bool second = isSecondEligible(nums, index) && solve(nums, index+3, dp);
        bool third = isThirdEligible(nums, index) && solve(nums, index+3, dp);

        return dp[index] = first || second || third;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};

// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/submissions/1539718313/