class Solution {
public:

    // for each num, check all the number in the range (num+size)
    // if the element exists then no need of any operations

    // N^2 solution and TLE
    
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp; // num, freq

        for(int num : nums){
            mp[num] = 1;
        }

        int minCount = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            int y = x + size - 1;

            int count = 0;

            for(int i=x; i<=y; i++){
                if(mp.find(i) == mp.end()){
                    count++;
                }
            }

            minCount = min(minCount, count);
        }

        return minCount;
    }
};
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/