class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // mark numbes as negative okay
        
        int dup = -1;
        for(int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i])-1;
            if(nums[index] > 0)
            {
                nums[index] *= -1;
            }
            
            else {dup = index+1; break;}
        }
        
        return dup;
    }
};

// ques: https://leetcode.com/problems/find-the-duplicate-number