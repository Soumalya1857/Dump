class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> map;
        for(int i=0; i< nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        vector<int> dp(nums.size()+1, -1);
        return solve(nums,map,dp,0);
    }

    int solve(vector<int> nums, unordered_map<int, vector<int>> &map, vector<int> &dp, int currIndex){
        if(currIndex >= nums.size()){
            return 0;
        }

        if(dp[currIndex] != -1) 
            return dp[currIndex];

        int localAns1 = 0, localAns2 = 0;

        // we can choose not to take the element
        if(dp[currIndex+1] != -1){
            localAns1 = dp[currIndex+1];
        }
        else{
            localAns1 = solve(nums, map, dp, currIndex+1);
        }
        
        // or we can take the element
        if(nums[currIndex] > 0){
            localAns2 = nums[currIndex];
            for(int index : map[nums[currIndex]-1]){
                if(nums[index] > 0) 
                    nums[index] *= -1;
            }

            for(int index : map[nums[currIndex]+1]){
                if(nums[index] > 0) 
                    nums[index] *= -1;
            }

            if(dp[currIndex+1] != -1){
                localAns2 += dp[currIndex+1];
            }
            else{
                localAns2 += solve(nums, map, dp, currIndex+1);
            }
            //localAns2 += solve(nums, map, dp, currIndex+1);
        }

        return dp[currIndex] = max(localAns1, localAns2);
    }
};

// solution: https://leetcode.com/problems/delete-and-earn/solutions/1820279/c-detailed-explanation-w-recursion-to-memoziation-understand-concept/

// problem: https://leetcode.com/problems/delete-and-earn/