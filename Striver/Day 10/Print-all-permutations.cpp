
class Solution {
public:
    void logic(vector<int> copy, int l, int r, vector<vector<int>> &ans)
    {
        if(l == r)
        {
            ans.push_back(copy);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            swap(copy[l], copy[i]);
            logic(copy, l+1, r, ans);
            // backtrack
            swap(copy[l], copy[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int size = nums.size();
        if(size == 0) return ans;
        logic(nums, 0, size-1, ans);
        return ans;
    }
};
// prb: https://leetcode.com/problems/permutations/submissions/
// soln: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52