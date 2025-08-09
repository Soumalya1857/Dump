class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxNow = 0;
        
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < maxNow + nums[i])
            {
                maxNow += nums[i];
            }
            else maxNow = nums[i];
            
            maxSum = max(maxSum, maxNow);
        }
        
        return maxSum;
    }
};

// problem: https://leetcode.com/problems/maximum-subarray/