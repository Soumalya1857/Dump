class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int res = -1;
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int size = nums.size();
        if(size==0) return ans;
        int low = 0, high = size-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(nums[mid] == target) res = mid, high=mid-1;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        cout << res << endl;
        ans[0] = res;
        low = 0, high = size-1,res=-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(nums[mid] == target) res=mid,low=mid+1;
            else if(nums[mid] < target) low = mid+1; 
            else high = mid-1;
        }
        cout << res << endl;
       ans[1] = res;
        return ans;
        
    }
};

// qus: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
// sol: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/1347937/Easy-C%2B%2B-Solution-with-only-one-Binary-Search-block
