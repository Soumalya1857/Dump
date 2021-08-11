class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size,1), suffix(size,1), ans(size,1);
        
        for(int i=1;i<size;i++) prefix[i] = prefix[i-1]*nums[i-1];
        for(int i=size-2;i>=0;i--) suffix[i] = suffix[i+1]*nums[i+1];
        
        for(int i=0;i<size;i++) ans[i] = prefix[i]*suffix[i];
        return ans;
    }
};

// prb: https://leetcode.com/problems/product-of-array-except-self/
// O(n) solution: https://leetcode.com/problems/product-of-array-except-self/discuss/1396172/Simple-Java-1ms-Faster-than-100-of-Submissions-(Time%3A-O(n)-Space%3A-0(1))