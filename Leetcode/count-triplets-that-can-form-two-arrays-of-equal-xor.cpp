class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        if(n==0) return 0;
        
        vector<int> dp(n);
        int count = 0;
        dp[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1] ^ arr[i];
        }
        
        // need to find two equal element in the dp arr
        // the positions are our i and k value
        // j can be anything in between
        
        // for(int i=0;i<n;i++) cout << dp[i] << ", ";
        // cout << "\n";
        
        for(int i=0;i<n;i++)
        {
            if(dp[i] == 0) count+= i;
            for(int j = i+1;j<n;j++)
            {
                
                if(dp[i] == dp[j])
                {
                    count += (j-i-1);
                    //cout << "dp[i]: " << dp[i] << "\n";
                    //cout << "i: " << i << "  j: " << j << endl;
                }
            }
        }
        
        return count;
    }
};

/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/