class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // one pointer to check the duplicates
        // one pointer to place them infront of the array
        
        int i=0,j=0;
        if(nums.size() == 0) return 0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1]) continue;
            else
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1; 
    }
};

// prob: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// soln: https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=43