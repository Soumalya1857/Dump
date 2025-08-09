class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==0) return {};
        
        int low = 0, high = n-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            //if((nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])) 
                //return nums[mid];
            if(mid % 2 ==1) mid--;
            if(nums[mid] != nums[mid+1]) high = mid;
            else low = mid + 2;
        }
        
        return nums[low];
    }
};

// better optimized solution

// int singleNonDuplicate(vector<int>& nums) {
//         int l = 0, r = nums.size() - 1;
//         if (r == 0 or nums[0] != nums[1]) return nums[0];
//         while(l <= r) {
//             int m = (l + r) / 2;
//             if (m & 1)
//                 nums[m - 1] == nums[m] ? l = m + 1 : r = m - 1;
//             else
//                 nums[m - 1] == nums[m] ? r = m - 1 : l = m + 1;
//         }
//         return nums[r];
//     }