class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        // count how one bit contribute to total hamming distance sum
        long long mask = 1L << 31;
        int j = 31;
        int count = 0;
        while(mask){
            int temp = 0;
            for(int i=0;i<nums.size();i++)
                if(nums[i] & mask) 
                    temp++;
            count += temp * (nums.size() - temp); // one bit will contribute to all other non-set bit
            mask = mask >> 1;
            j--;
        }
        
        return count;
    }
};

// https://leetcode.com/problems/total-hamming-distance
// good solution