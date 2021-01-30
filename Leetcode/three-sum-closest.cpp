class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        int diff = INT_MAX;
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<size;i++)
        {
            int num = nums[i];
            int low = i+1;
            int high = size-1;
            
            while(low < high)
            {
                int sum = num + nums[low] + nums[high];
                if(abs(target-sum) < abs(diff))
                    diff = target - sum;
                
                if(diff == 0) break;
                if(sum < target)
                    low++;
                else
                    high--;
                
            }
        }
        
        return target - diff;
    }
};

// solution: https://leetcode.com/problems/3sum-closest