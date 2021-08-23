class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // from last we are seeing if we can reach the first index or not
        int lastGoodIndex = nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i + nums[i] >= lastGoodIndex)
            {
                lastGoodIndex = i;
            }
        }
        
        return lastGoodIndex == 0;
    }
};
// soln: https://leetcode.com/problems/jump-game/submissions/
// https://www.youtube.com/watch?v=Zb4eRjuPHbM