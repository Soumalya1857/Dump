// Errored but good idea this is
// https://leetcode.com/problems/constrained-subsequence-sum/
class Solution {

private:
    int solve(vector<int> &nums, int index, int prev, int k, int sum, vector<vector<int>> &dp){
        if(index >= nums.size()){
            return sum;
        }

        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }


        if(prev == -1 || ((index-prev) <= k)){
            return dp[index][prev+1] = max(
                                            solve(nums, index+1, prev, k, sum, dp),
                                            solve(nums, index+1, index, k, sum+nums[index], dp)
                                        );
        }else{
            return dp[index][prev+1] = solve(nums, index+1, prev, k, sum, dp);
        }
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        int ans = solve(nums, 0, -1, k, 0, dp);


        int maxi = -1e9;
        for(int num : nums){
            maxi = max(maxi, num);
        }

        return ans == 0 ? maxi : ans;
    }
};

// ================================================

// https://leetcode.com/problems/constrained-subsequence-sum/solutions/4192873/c-solution-intuitive-optimized-sliding-window-heap-lis-detailed-explanation/

