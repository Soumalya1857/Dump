class Solution {
public:
    int jump(vector<int>& nums) {
    
        
        // correct soln but gives TLE for big input
        
//         int n = nums.size();
//         if(n==1) return 0;
//         vector<int> dp(n+1, INT_MAX);
        
//         dp[1] = 0;
//         for(int i=1;i< n;i++)
//         {
//             for(int j=1; j<= nums[i-1]; j++)
//             {
//                 if(i+j <= n)
//                 {
//                     if(dp[i+j] > 1 + dp[i])
//                         dp[i+j] = 1 + dp[i];
//                 }
//             }
//         }
        
//         return (dp[n]==INT_MAX)? -1: dp[n];
        
        //return 1;
        
        
        
        
        // greedy approach
        
        
        
        
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        // If we have 2 or more elements then we surely need atleast 1 jump to reach end
        int jumps = 1;
        // maxpossible index denotes the max possible index that we can reach if we
        // take a jump of value denoted by a[i]
        int max_possible_index = nums[0];
        // Denotes the steps that we require to reach maxpossible index
        int steps = nums[0];
        
        // Loop till n-1 because, from second last cell i.e n-2 we just need 1 step
        for (int i = 1; i<n-1; i++) {
            if (i + nums[i] > max_possible_index) {
                max_possible_index = i + nums[i];
            }
            steps--;
            if (steps == 0) {
                // If steps become 0, then we need to take a jump
                // and steps will be now initialized again, with the value, that denotes
                // the required steps to reach maxpossible index, from position i
                jumps++;
                steps = max_possible_index - i;
            }
        }
        return jumps;
    }
};


/*
https://leetcode.com/problems/jump-game-ii
*/