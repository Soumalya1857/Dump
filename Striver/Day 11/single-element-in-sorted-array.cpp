class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // trick is the index position
        // if(even index == even+1 index   --> single element on right)
        // else single element on left
        
        int size = nums.size();
        int low=0, high=size-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(mid+1 < size && nums[mid] == nums[mid+1]) 
            {
                if(mid % 2 == 0) low = mid+1;
                else high = mid;
            }
            else if(mid-1 >= 0 && nums[mid] == nums[mid-1])
            {
                if(mid % 2 == 0) high = mid;
                else low = mid+1;
            }
            else
            {
                return nums[mid];
            }
        }
        return -1;
    }
};
// prb: https://leetcode.com/problems/single-element-in-a-sorted-array/
// ans: https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=64