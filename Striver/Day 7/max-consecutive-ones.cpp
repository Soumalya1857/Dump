class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=INT_MIN, i=0,j=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                ans = max(ans, i-j+1);
            }
            else
            {
                while( i<nums.size() && nums[i] != 1)
                {
                    ++i;
                }
                
                if(i == nums.size()) break;
                j = i;
                ans = max(ans,i-j+1);
            }
        }
        
        
        
        return ans != INT_MIN ? ans : 0;
    }
};

// prb: https://leetcode.com/problems/max-consecutive-ones/
// soln: https://www.youtube.com/watch?v=Mo33MjjMlyA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=44

// simpler solution

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0, maxi = 0;
        
        for(int num : nums)
        {
            if(num == 1)
            {
                ++count;
                maxi = max(maxi,count);
            }
            else count = 0;
        }
        
        return maxi;
    }
};