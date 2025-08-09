class Solution {
public:
// https://leetcode.com/problems/russian-doll-envelopes/solutions/82763/java-nlogn-solution-with-explanation/
    
    //struct compare
   static bool compare(const vector<int>&a, const vector<int>&b)
    {
        return (a[0] < b[0])||(a[0]==b[0]&&a[1]>b[1]);
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // we need to sort them wrt the first element
        
         int n = envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(), envelopes.end(), compare);
       
        // need to calculate LIS based on the 2nd element of the envelops
        int maxi = -1;
        
        vector<int> lis(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j = 0; j<i ;j++)
            {
                if(envelopes[i][1] > envelopes[j][1])
                {
                    if(lis[i] < lis[j] + 1)
                    {
                        lis[i] = lis[j]+1;    
                    }
                }
            }
            maxi = max(maxi, lis[i]);
        }
        
        return maxi;
        
    }
};

// https://leetcode.com/problems/russian-doll-envelopes/