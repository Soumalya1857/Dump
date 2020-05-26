bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        if(n==0) return false;
        int low=0,high=n-1;
        
        
        if(nums[n-1]>nums[0])  // this is just an extra condition to check if the array has been rotated or not
        {
            int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(idx==n) return false;
            if(nums[idx]!=target) return false;
            return true;
        }
        
       
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target) return true;
            
            else if(nums[mid]>nums[high]) 
            {
                if(nums[mid]>target)
                {
                    if(nums[low]<=target) high=mid-1;
                    else low=mid+1;
                }
                else
                {
                    low=mid+1;
                }
            }
            
            else if(nums[mid]<nums[high])
            {
                if(nums[mid]>target) high=mid-1;
                else
                {
                    if(nums[high]>=target) low=mid+1;
                    else high=mid-1;
                }
            }
            
            else high--;
        }
        
        return false;
    } 