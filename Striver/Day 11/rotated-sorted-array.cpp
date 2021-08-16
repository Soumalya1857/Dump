class Solution {
public:
    int search(vector<int>& nums, int target) {
        
//         int size = nums.size();
//         if(nums.size() == 0) return -1;
//         if(nums.size() == 1) 
//         {
//             if(nums[0] == target) return 0;
//             return -1;
//         }
//         int low = 0;
//         int high = nums.size() - 1;
        
//         // pivot baar kore again binary search
//         int pivot = -1;
        
//         while(low < high)
//         {
//             int mid = (low+high)/2;
//             if(nums[mid] < nums[(mid+1)%size] && nums[((mid-1)+size)%size] > nums[mid]) {pivot = mid; break;}
//             else if(nums[mid] > nums[high]) low = (mid+1)%size;
//             else if(nums[mid] < nums[low]) high = ((mid-1)+size)%size;
//         }
        
//         cout << "pivot: " << pivot << endl;
//         low = 0;
//         high = nums.size() - 1;
        
//         if(target > nums[nums.size()-1]) {
//             high = pivot-1;
//             low = 0;
//         } 
//         else
//         {
//             low = pivot;
//             high = nums.size()-1;
//         }
//         cout << "low: " << low << " high: " << high << endl;
//         while(low <= high)
//         {
//             int mid = (low + high)/2;
//             if(nums[mid] == target) return mid;
//             else if(nums[mid] > target) high = mid-1;
//             else if(nums[mid] < target) low = mid+1;
//         }
        
//         return -1;
        
//         int low = 0, high = nums.size()-1;
//         while(low <= high)
//         {
//             int mid = (low+high)/2;
//             if(nums[mid] == target) return mid;
     
//             else if(nums[mid] > target)
//             {
//                 if(nums[mid] > nums[low] && nums[low] <= target)
//                 {
//                     high = mid-1;
//                 }
//                 // else if(nums[mid] )
                
//                 else
//                 {
//                     low = mid+1;
//                 }
//             }
//             else if(nums[mid] < target)
//             {
//                 if(nums[mid] < nums[high] && nums[high] >= target)
//                 {
//                     low = mid+1;
//                 }
//                 else if(nums[mid] >= nums[low]) low = mid+1;
//                 else 
//                 {
//                     high = mid-1;
//                 }
//             }
//         }
        
//         return -1;
        
        
        int low = 0, high=nums.size()-1;
        while(low <= high)
        {
            //cout << "low: " << low << " High: " << high << endl;
            int mid = (low + high) >> 1;
            if(nums[mid] == target) return mid;
            
            // check left half is sorted or not
            if(nums[low] <= nums[mid])
            {
                // check where the target lies
                if(nums[low]<= target && target < nums[mid])
                {
                    // element on left side
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            
            // right half is sorted
            else
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid+1;   
                }
                else 
                {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};

// prb: https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
// soln; https://www.youtube.com/watch?v=r3pMQ8-Ad5s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67