class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        bool possible = next_permutation(nums.begin(),nums.end());
        if(!possible) sort(nums.begin(),nums.end());
    }
};

/*
https://leetcode.com/problems/next-permutation/submissions/
*/

########################################################################3
// however we should know the exact better solution

