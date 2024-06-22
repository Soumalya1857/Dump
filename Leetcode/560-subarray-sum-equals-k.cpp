class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        unordered_map<int,int> mp;

        int result = 0;

        int prefixSum = nums[0];
        mp[prefixSum]++;

        mp[0]++;

        if(k == nums[0]) result++;

        for(int i=1; i<nums.size(); i++){
            prefixSum = nums[i] + prefixSum;
            int target = prefixSum - k;

            if(mp.find(target) != mp.end()){
                result += mp[target];
            }

            mp[prefixSum]++;
        }

        return result;
    }
};

// https://leetcode.com/problems/subarray-sum-equals-k/