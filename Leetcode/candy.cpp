class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int size = ratings.size();
        vector<int> dp(size,1);
        int sum = 0;
        
        // dp[size+1][3]
        // 0-> smaller than both
        // 1 -> geater then both
        // 2 -> greater then only 1side
        
        // once left to right traverse 
        // once right to left traverse
        
        for(int i=1;i<size;i++)
        {
            if(ratings[i] > ratings[i-1]) dp[i] = max(dp[i], dp[i-1]+1);
        }
        for(int i=size-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1]) dp[i] = max(dp[i],dp[i+1]+1);
        }
        
        // now sum
        for(int x : dp) sum += x, cout << x << " ";
        
        return sum;
    }
};
// prob: https://leetcode.com/problems/candy