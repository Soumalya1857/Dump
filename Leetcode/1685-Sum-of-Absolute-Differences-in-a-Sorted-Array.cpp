class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int size = nums.size();
        vector<int> result, prefix(nums.size());
        long long sum = nums[0];

        prefix[0] = nums[0];
        for(int i=1; i<size;i++){
            sum += nums[i];
            prefix[i] = prefix[i-1]+nums[i];
        }

        for(int i=0; i<size; i++){
            result.push_back((nums[i]*(i+1) - prefix[i]) + (sum-prefix[i] - nums[i]*(size-i-1)));

        }

        return result;
    }
};

// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/