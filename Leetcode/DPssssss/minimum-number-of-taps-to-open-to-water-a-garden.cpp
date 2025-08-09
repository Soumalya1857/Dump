class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        // this is a very good problem and i can't do it by my own
        // goood youtube solution
        // dp[i] -> min taps needed to water upto ground i
        
        vector<long long int> dp(n+1, INT_MAX);
        
        dp[0] = 0; // no ground no taps
        for( int i=0;i<n+1;i++)
        {
            int left = max(0, i-ranges[i]);
            int right = min(n, i+ranges[i]);
            
            for( int j=left; j<right+1;j++)
            {
                dp[j] = min(dp[j], 1+dp[left]);
            }
        }
        
        return dp[n] < INT_MAX ? dp[n] : -1;
    }
};

// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// gfg soln: https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/
// youtube: https://www.youtube.com/watch?v=XFvX7uMo7uk
// soln: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/discuss/1386524/2-solutions-DP-and-Greedy-with-how-you-behave-when-being-asked-during-interviews