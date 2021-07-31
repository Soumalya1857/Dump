class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0 || size == 1) return false;
        
        long long int sum = 0;
        for(int i=0;i<size;i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2 == 1) return false;
        
        sum /= 2;
        // dp[i][j] is it possible to get to target with array elements 0...i
        
        vector<vector<bool>> dp(size+1,vector<bool>(sum+1,false));
        
        // initial cases
        for(int i=0;i<size;i++) if(nums[i] <= sum) dp[i][nums[i]] = true;
        
        for(int i=1;i<size;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                // j is achieveable using ith element only if i-1,j is achievable or i-1,-nums[i] is achievable
                if(j >= nums[i])
                {
                    if(dp[i-1][j] == true || dp[i-1][j-nums[i]] == true)
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if(dp[i-1][j]) dp[i][j] = true;
                }
            }
        }
        
        return dp[size-1][sum];
    }
};

/*
question: https://leetcode.com/problems/partition-equal-subset-sum/
https://www.geeksforgeeks.org/subset-sum-queries-using-bitset/

https://leetcode.com/problems/target-sum/discuss/97334/java-15-ms-c-3-ms-ons-iterative-dp-solution-using-subset-sum-with-explanation
includes state compression
*/


// elegent solution
class Solution {
public:
    bool canPartition(vector<int>& nums) {
         bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);
        if (total % 2) return false;
        int sum_required = total / 2;
        vector<bool> subsetSum(sum_required + 1, false);
        subsetSum[0] = true;
        for(auto num : nums) {
            for(int i = sum_required; i>= num; i--) {
                if (subsetSum[i - num]) subsetSum[i] = true;
            }
        }
        
        return subsetSum[sum_required];
    }
};



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};